
---------------------------------------------------------------------------

开始的时候我们可以做的简单一点   把所有详细的日志数据插入到一张表中
我们的整合可以一天从这张表中把符合这一天的数据整合到天表  每一个月
把一个月的数据整合到月表

这样的话我们可以通过一条sql直接把符合查询的数据插入到对应的表
涉及的存储过程如下：
一天执行一次的存储过程
create or replace   procedure  day_zhenghe
as
begin
   execute immediate 'insert into  daydata'||to_char(sysdate,'dd')||  
        ' select max(id),max(username),max(logouttime),sum(durations) '||
	    'from  logdetailts  where  logouttime>='''||to_date(trunc(sysdate,'dd'))  
	       ||''' and  logouttime<'''||to_date(trunc(sysdate+1,'dd'))||
	       ''' group by username ';
    commit;
end;
一个月执行一次的存储过程
create or replace   procedure  month_zhenghe
as
begin
    execute immediate 'insert into  monthdata'||to_char(sysdate+1,'mm')||  
        ' select max(id),max(username),max(logouttime),sum(durations) '||
	    'from  logdetails  where  logouttime>='''||to_date(trunc(sysdate,'mm'))  
	       ||''' and  logouttime<'''||to_date(trunc(add_months(sysdate,1),'mm'))||
	       ''' group by username ';
end;



---------------------------------------------------------------------------------
 做的复杂一些如下：
 先创建 序列和表
 create sequence  test_s;
 创建一个存储过程 创建31张表 用来存储每天的详细信息  
 如1月1号的和2月1号的都存入logdetailt1中
 create  or replace  procedure createlogtables 
 is
 begin 
    for  i in 1..31  loop
       execute immediate 'create table  logdetailt'||i||'(
      id  number primary key,
      username  varchar(30),
      logouttime  date,
      durations   number)';
    end loop;
 end;
 删除31张表
 create  or replace  procedure droplogtables 
 is
 begin 
    for  i in 1..31  loop
       execute immediate 'drop table  logdetailt'||i;
    end loop;
 end;
 select trunc(dbms_random.value(0,20)) from dual;
 
 同时创建31张用于统计数据的天数据表
 create  or replace  procedure createdaydatatables 
 is
 begin 
    for  i in 1..31  loop
       execute immediate 'create table  daydata'||i||'(
      id  number primary key,
      username  varchar(30),
      logouttime  date,
      durations   number)';
    end loop;
 end;
 删除31张表
 create  or replace  procedure dropdaydatatables 
 is
 begin 
    for  i in 1..31  loop
       execute immediate 'drop table  daydata'||i;
    end loop;
 end;

 创建12个月的月数据表
 create  or replace  procedure createmonthdatatables 
 is
 begin 
    for  i in 1..12  loop
       execute immediate 'create table  monthdata'||i||'(
      id  number primary key,
      username  varchar(30),
      logouttime  date,
      durations   number)';
    end loop;
 end;
 删除12张表
 create  or replace  procedure dropdatatables 
 is
 begin 
    for  i in 1..12  loop
       execute immediate 'drop table  monthdata'||i;
    end loop;
 end;
 模拟数据   5分钟插入一次数据  模拟完成后让统计程序去统计这些数据
 根据当前的日期选择插入相应的表  1号放入表1  2号的数据放入表2
 
 模拟的存储过程如下：
 create or replace procedure data_moni  
 is
    uname  varchar(30);
 begin    
     execute immediate 'insert into logdetailt'||to_char(sysdate,'dd')||'(id,username,logouttime,durations)' 
     ||'values(test_s.nextval,''test''||to_char(trunc(dbms_random.value(0,20)))
     ,sysdate,trunc(dbms_random.value(0,15)))';
     commit;
 end data_moni;
 如果一下写不出上面这么动态的  可以先写这么一个简单点的  然后写出上面的代码
 create or replace procedure data_moni  
 is
    uname  varchar(30);
 begin    
     execute immediate 'insert into logdetailt'||to_char(sysdate,'dd')||'(id,username,logouttime,durations)' 
     ||'values(test_s.nextval,''test'',''1-AUG-11'',10)';
     commit;
 end data_moni;

 

创建调度程序  按每5分钟调度一次模拟插入数据的存储过程  具体多长时间自己调整后面的第三个参数就可
第一个参数是工作号 第二个是调用的存储过程  第三个是开始时间  第四个是下一次执行的时间
 declare
   jobno  binary_integer;
 begin     
     dbms_job.submit(jobno,'data_moni;',sysdate,'sysdate+1/(24*12)'); 
     dbms_output.put_line(jobno);
     dbms_job.run(jobno);
     commit;
 end;
 
把程序调用  

创建存储过程 按照一天整合一次的原则 把前一天的数据整合到天表中
这个时候要想着去更新月表 到一个月的时候要更新年表
存储过程如下：


create  sequence  test_s_s;
create or replace   procedure  day_zhenghe
as
begin
   execute immediate 'insert into  daydata'||to_char(sysdate-1,'dd')||  
        ' select test_s_s.nextval,u,t ,d from (select max(username) u,max(logouttime) t,sum(durations) d '||
	    'from  logdetailt'||to_char(sysdate-1,'dd')||'  where  logouttime>='''||to_date(trunc(sysdate,'dd'))  
	       ||''' and  logouttime<'''||to_date(trunc(sysdate+1,'dd'))||
	       ''' and username not in(select distinct username 
	       from  daydata'||to_char(sysdate-1,'dd')||') group by username)';
  
    commit;
end;


这个时候天数据表中已经有数据了  我们完全可以从天数据表中取数据放入月数据表中
但这个过程中可能有的数据要更新 有的数据是插入 这个就相对复杂一些
create or replace   procedure  month_zhenghe
as
sqlstr  varchar2(200);
type  day_cur  is ref cursor;
data  monthdata2%rowtype;
begin
    /*
    1.先得到整合数据 放入cursor中
    2.根据条件决定是插入还是更新
    */
    sqlstr:='select max(username) u,max(logouttime) t,sum(durations) d '||
	    'from  logdetailt'||to_char(sysdate-1,'dd')||'  where  logouttime>='''||to_date(trunc(sysdate,'dd'))  
	       ||''' and  logouttime<'''||to_date(trunc(sysdate+1,'dd'))||
	       ''' group by username';
    open day_cur for sqlstr;
    fetch  day_cur into data;
    dbms_output.put_line(data.id);
    close day_cur;
end;

create or replace   procedure  month_zhenghe
as
sqlstr  varchar2(200);
type  data_cur  is ref cursor;
data  monthdata2%rowtype;
daycur  data_cur;
uname varchar2(30);
ucount number:=0;
begin
    sqlstr:='select max(id),max(username) u,max(logouttime) t,sum(durations) d '||
	    'from  logdetailt'||to_char(sysdate,'dd')||'  where  logouttime>='''||to_date(trunc(sysdate,'dd'))  
	       ||''' and  logouttime<'''||to_date(trunc(sysdate+1,'dd'))||
	       ''' group by username';
    open  daycur for sqlstr;
    loop
    fetch daycur into data;
    exit when daycur%notfound;
    dbms_output.put_line(data.username);
    sqlstr:='select count(*)  from monthdata'||to_char(trunc(sysdate,'mm')-1,'fmmm')||
    ' where username='''||data.username||'''';
    execute immediate  sqlstr into ucount;
    dbms_output.put_line(ucount);
    if  ucount=0 then
    execute immediate 'insert into monthdata'||to_char(trunc(sysdate,'mm')-1,'fmmm')||' values
    (test_s_s.nextval,'''||data.username||''','''||data.logouttime||''','||data.durations||')';
    else
    execute immediate 'update monthdata'||to_char(trunc(sysdate,'mm')-1,'fmmm') ||' set 
    logouttime='''||data.logouttime||''',durations=durations+'||data.durations||' where username='''||data.username
    ||'''';
    end if;
    end loop;
 close daycur;
end;

