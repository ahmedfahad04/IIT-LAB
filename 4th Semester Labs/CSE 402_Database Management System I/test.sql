
/*

-- Function creation and declaration --

CREATE FUNCTION get_sal (p_id employees.employee_id%TYPE) 
RETURN NUMBER IS

--- Here employees.salary%TYPE == DATATYPE of employees.salary, that means it always indicate the DATATYPE ---

v_sal employees.salary%TYPE := 0;

BEGIN
	SELECT salary
	INTO v_sal
	FROM employees
	WHERE employee_id = p_id;
	RETURN v_sal;
END get_sal;
/


SET SERVEROUTPUT ON;
BEGIN 
	DBMS_OUTPUT.PUT_LINE(get_sal(100));
END;
/


---- OR ----

SET SERVEROUTPUT ON;
DECLARE
	value NUMBER(10);
BEGIN 
	value := 100;
	DBMS_OUTPUT.PUT_LINE(get_sal(value));
END;
/





--- a Refurbished form of the Above function ---

CREATE FUNCTION get_sal (p_id NUMBER) 
RETURN NUMBER IS


v_sal NUMBER := 0;

BEGIN
	SELECT salary
	INTO v_sal
	FROM employees
	WHERE employee_id = p_id;
	RETURN v_sal;
END get_sal;

*/

-- create or replace procedure demo(pid IN number, num out varchar2) is 

-- begin 
--     select phone_number
--     into num 
--     from employees
--     where employee_id = pid;
  
-- end demo;
-- /

-- set serveroutput on;
-- declare
--     v_ph varchar2(20);
-- begin
--     demo(100, v_ph);
--     DBMS_OUTPUT.PUT_LINE(v_ph);
-- end;
-- /


-- create or replace function demo2(pid number) 
-- return varchar is

-- v_phone varchar;

-- begin 
--     select phone_number 
--     into v_phone 
--     from employees
--     where employee_id = pid
--     return v_phone;
-- end demo2;


-- begin
--     dbms_output.put_line(demo2(100))
-- end;
-- /

-- create or replace procedure areac (r number, a out number) is 

-- begin
--     select 3.14*r*r
--     into a 
--     from dual;
    
-- end;
-- /

-- declare 
--     aa number;
-- begin 
--     areac(2, aa);
--     DBMS_OUTPUT.PUT_LINE(aa);
-- end;
-- /

-- create or replace function areacc (r number) return number is 

-- val number := 0;

-- begin
--     select 3.14*r*r 
--     into val 
--     from dual
--     return val;
-- end areac;
-- /

-- begin
--     DBMS_OUTPUT.PUT_LINE(areacc(2));
-- end;
/
