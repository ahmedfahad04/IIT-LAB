create or replace procedure carea4(r in NUMBER, area out NUMBER) is

pi constant number := 3.14;

begin
	area := pi * r * r;
	-- select pi*r*r 
	-- into area
	-- from dual;
end carea4;
/


declare 
	ans number;
begin
	carea4(5, ans);
	DBMS_OUTPUT.PUT_LINE(ans);
end;
/



create or replace function carea (r NUMBER)
return number is

pi constant number := 3.14;
area number := 0;

begin
	-- area := pi * r * r;
	select 3.1416*r*r 
	into area
	from dual;
	return area;
end carea;
/


set serveroutput on;
begin
	DBMS_OUTPUT.PUT_LINE(carea(5));
end;
/





-- create or replace function tax(p_id employees.employee_id%TYPE) 
-- return number is
-- ans number := 0;

-- BEGIN
-- 	SELECT (12*(salary+salary*nvl(commission_pct,0)))*.1
-- 	INTO ans
-- 	FROM employees
-- 	WHERE employee_id = p_id;

-- 	RETURN ans;
-- end tax;
-- /



-- begin 
-- 	DBMS_OUTPUT.PUT_LINE(tax(100));
-- end;
-- /



/*
set serveroutput on;
declare
	n1 number := 10;
	n2 number := 5;
	n3 number := 11;
	ans number;
begin
	if n1 >= n2 and n1 >= n3 
	then 
		ans := n1;
		DBMS_OUTPUT.PUT_LINE(ans); 
	end if;

	if n2 >= n1 and n2 >= n3 
	then 
		ans := n2;
		DBMS_OUTPUT.PUT_LINE(ans); 
	end if;

	if n3 >= n2 and n3 >= n1
	then 
		ans := n3;
		DBMS_OUTPUT.PUT_LINE(ans); 
	end if;

	
	DBMS_OUTPUT.PUT_LINE(ans); 

end;

/




declare
	n1 number := 10;
	n2 number := 5;
	n3 number := 11;
	ans number := 0;
begin
	if n1 >= n2 and n1 >= n3 
	then 
	-- properly give the semicolon --
		ans := n1; 
	elsif n2 >= n1 and n2 >= n3 
	then 
		ans := n2;
	elsif n3 >= n2 and n3 >= n1
	then 
		ans := n3;
	end if;

	DBMS_OUTPUT.PUT_LINE(ans); 

end;
/


*/