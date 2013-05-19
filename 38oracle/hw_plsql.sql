--------------------------------------------------------------------------------
	--使用动态的sql创建30个表
	create or replace procedure mk_31_tabls is
	begin
		for i in 1..31 loop
		    execute immediate 
		    'create table tab_'||i||'( id number primary key,name varchar2(30))';
		    dbms_output.put_line('create table tab_'||i||'( id number primary key,name varchar2(30))');
		  end loop;
	end;
	--删除这30张表
	create or replace procedure del_31_tabls is
	begin
		for i in 1..31 loop
		      execute immediate 'drop table tab_'||i;
		      dbms_output.put_line('drop table tab_'||i);
		    end loop;
	end;
--------------------------------------------------------------------------------
   	--写一个过程  得到s_emp 中部门的个数
   	--写一个函数  得到s_emp 中部门的个数
	--procedure
	create or replace procedure get_dept_pro(var_n out number) is
	begin
		select count(*) into var_n from  
	  	 (select dept_id from s_emp group by dept_id having dept_id is not null);
	end get_dept_pro;
	--function
	create or replace function get_dept_fun return number 
	is
		var_n number;
	begin
		select count(*) into var_n from  
	  	       (select dept_id from s_emp group by dept_id having dept_id is not null);	
		return var_n;
	end get_dept_fun;
	--PL/SQL
	declare 
		var_1 number;
		var_2 number;
	begin 
	      get_dept_pro(var_1);
	      dbms_output.put_line('var_1='||var_1);
	      var_2:=get_dept_fun();
	      dbms_output.put_line('var_2='||var_2);
	end;
--------------------------------------------------------------------------------	
	--作业:写一个包 里面有一个函数 一个过程  过程和函数如上一个作业中
     	--得到员工数的要求相同 
     	--再写一个匿名块测试所写的函数和过程
	--package header
	create or replace package abc_pack is
	  procedure	get_dept_pro(var_n out number);
	  function	get_dept_fun return number;
	 end abc_pack;
	--package body
	create or replace package body abc_pack is
	  procedure  get_dept_pro(var_n out number)
	  	    is
		    begin
		     select count(*) into var_n from  
	  	       (select dept_id from s_emp group by dept_id having dept_id is not null);	
		    end get_dept_pro;
	 function get_dept_fun return number
	 	  is
			var_n number;
		  begin
	  	  select count(*) into var_n from  
	  	       (select dept_id from s_emp group by dept_id having dept_id is not null);	
		  return var_n;
		  end get_dept_fun;
	end abc_pack;
	--test PL/SQL
	declare 
		var_1 number;
		var_2 number;
	begin 
	      abc_pack.get_dept_pro(var_1);
	      dbms_output.put_line('var_1='||var_1);
	      var_2:=abc_pack.get_dept_fun();
	      dbms_output.put_line('var_2='||var_2);
	end;
--------------------------------------------------------------------------------