------------------ FUNCTION -------------------

create or replace function sal(pid employees.employee_id%TYPE) 
return number 
is 

    v_sal employees.employee_id%TYPE;

begin
    select 12*(salary + salary * nvl(commission_pct, 0))
    into v_sal
    from employees
    where employee_id = pid;

    return v_sal;
end sal;
/

set serveroutput on;
declare 
    vin number := &vin;
begin 
dbms_output.put_line('Salary: ' || sal(vin));
end;
/


-------- PROCEDURE -----------

create or replace procedure sal2(pid in employees.employee_id%TYPE, ans out number) 
-- [Func: return type]
is 

-- [Func: new variable to store output and then return]

begin
    select 12*(salary + salary * nvl(commission_pct, 0))
    into ans -- this param is passed through thee procedure
    from employees
    where employee_id = pid;
    -- [Func: return statement]
end sal2;
/

set serveroutput on;
declare 
    vin number;
    res number; -- new variable to store the output
begin 
    sal2(&vin, res);
    dbms_output.put_line(res);
end;
-- /



