create table customer(
    id   number primary key,
    cno  varchar2(20),
    cname varchar2(30)
);
insert into customer values(1,'002','zhangsan');
子表
create table corder(
    id   number primary key,
    ono  varchar2(20),
    fid  number,
    constraint c_u unique fid, constraint test_fk foreign key fid references customer(id)
);

insert into corder values(1,'001',null);
insert into corder values(2,'001',1);
insert into corder values(3,'001',1);//error 唯一性约束


多对多的关系
create table  student(
id  number primary key,
sno  varchar2(30),
sname varchar2(30)
);
create table  course(
id  number primary key,
cno  varchar2(30),
cname varchar2(30)
);

关系表

create table s_c(
id  number primary key,
sid  number  references student(id),
cid   number references course(id)
--, primary key(sid,cid)
);