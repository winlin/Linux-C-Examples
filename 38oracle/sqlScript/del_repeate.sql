declare
	type nam_tab is table of stu_test.name%type index by binary_integer;
	v_nam_tab nam_tab;
	type flg_tab is table of number index by binary_integer;
	v_flg_tab flg_tab;
	
	str stu_test.name%type;
	name_count number;
	rcd_count number;
begin
	create or replace view viw_name as
	       select name from stu_test group by name;
	--获得所有记录条数
	select count(id) into rcd_count from stu_test;
	--获得不重复的名字的个数
	select count(name) into name_count from viw_name;

	for i in 1..name_count loop
	    --把每个名字保存
	    select name into v_nam_tab(i) from viw_name;
	end loop;

	for i in 1..rcd_count loop
	    select name into str from stu_test where id=i;
	    for j in 1..name_count loop
	    	if str=v_nam_tab(j) and v_flg_tab(i)!=1 then
		   v_flg_tab:=1;
		   goto  here;
		end if;
	    end loop;

	   delete from stu_test where id=i;
        <<here>>
	end loop;

end;