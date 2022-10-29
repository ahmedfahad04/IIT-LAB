-- [1. Update data in a table for rows that match the supplied parameter values]
create or replace procedure chng_id(p_id in jobs.job_id%TYPE)
is

begin
    update jobs
    set max_salary = max_salary-1000
    where job_id = p_id;
    DBMS_OUTPUT.PUT_LINE('ROW UPDATED: ' || SQL%ROWCOUNT); --rowcount means how many rows have been changed
end chng_id;
/

set serveroutput on;
begin
    chng_id('ST_MAN');
end;
/



-- [2. Delete rows from a table that match the supplied parameter values]
create or replace procedure del_row(p_name in varchar2)
is

begin
    delete
    from new_client
    where name = p_name;
end del_row;
/

set serveroutput on;
begin
    del_row('Rukmini');
end;
/



-- [3. Insert new rows into a table using the supplied parameter values]
create or replace procedure add_row(p_id in varchar2, p_title in varchar2, p_max in number, p_min in number)
is

begin
    insert into jobs values (p_id, p_title, p_max, p_min);
end add_row;
/

set serveroutput on;
begin
    add_row('AS_PRO', 'Assistant Programmer', 75000, 25000);
end;
/ 


-- [4. Query a table and retrieve data based on supplied parameter values]
create or replace procedure sal2(pid in employees.employee_id%TYPE, ans out number) 
is 

begin
    select 12*(salary + salary * nvl(commission_pct, 0))
    into ans 
    from employees
    where employee_id = pid;
end sal2;
/

set serveroutput on;
declare 
    vin number;
    res number; 
begin 
    sal2(&vin, res);
    dbms_output.put_line(res);
end;
/

