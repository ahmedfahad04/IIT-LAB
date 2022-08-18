
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
*/

---- OR ----

SET SERVEROUTPUT ON;
DECLARE
	value NUMBER(10);
BEGIN 
	value := 100;
	DBMS_OUTPUT.PUT_LINE(get_sal(value));
END;
/





/*
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