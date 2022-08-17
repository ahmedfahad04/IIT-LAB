/*

CREATE FUNCTION get_sal (p_id employees.employee_id%TYPE) 
RETURN NUMBER IS

--- Here employees.salary%TYPE == DATATYPE of employees.salary, that means it always indicate the DATATYPE ---

v_sal employees.salary%TYPE := 0;

BEGIN
	SELECT salary
	INTO v_sal
	FROM employees
	WHERE employee_id = p_id
	RETURN v_sal;
END get_sal;


SET SERVEROUTPUT ON;
BEGIN 
	DBMS_OUTPUT.PUT_LINE(get_sal(100));
END;

*/

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
