create table stu_key(
		id number primary key,
		name varchar(20),
		course number(5)
);

create sequence id_num;

insert into stu_test values(id_num.nextval,'wingling',00001);
insert into stu_test values(id_num.nextval,'wingling',00002);
insert into stu_test values(id_num.nextval,'wingling',00003);
insert into stu_test values(id_num.nextval,'wingling',00004);
insert into stu_test values(id_num.nextval,'liuhong' ,00001);
insert into stu_test values(id_num.nextval,'liuhong',00002);
insert into stu_test values(id_num.nextval,'liuhong',00003);
insert into stu_test values(id_num.nextval,'liuhong',00004);
insert into stu_test values(id_num.nextval,'zhangsan',00001);
insert into stu_test values(id_num.nextval,'zhangsan',00002);
insert into stu_test values(id_num.nextval,'zhangsan',00003);
insert into stu_test values(id_num.nextval,'zhangsan',00004);
insert into stu_test values(id_num.nextval,'lisi',00001);
insert into stu_test values(id_num.nextval,'lisi',00002);
insert into stu_test values(id_num.nextval,'lisi',00003);
insert into stu_test values(id_num.nextval,'lisi',00004);

--把名字相同的只留一条
--delete from stu_test where id not in (select min(id) from stu_test group by name);

