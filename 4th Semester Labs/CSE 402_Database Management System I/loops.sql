purge recyclebin


declare 
    v_counter number:= 0;
begin
    loop
        v_counter := v_counter + 1;
        exit when v_counter > 10;
        
         DBMS_OUTPUT.PUT_LINE('v counter = ' ||  v_counter);
    end loop;
end;
/

declare 
    v_counter number:= 10;
begin
    while v_counter > 0
    loop
        DBMS_OUTPUT.PUT_LINE('v counter = ' ||  v_counter);
        v_counter := v_counter - 1;
    end loop;
end;
/


declare 
    v_counter number:= 10;
begin
    while v_counter > 0
    loop
        DBMS_OUTPUT.PUT_LINE('v counter = ' ||  v_counter);
        v_counter := v_counter - 1;
        if v_counter = 5 then exit;
        end if;
    end loop;
end;
/


begin 

    for a in 1..10
    loop 
        DBMS_OUTPUT.PUT_LINE('a = ' || a);
    end loop;

end;
/

begin 

    for b in reverse 1..10
    loop 
        DBMS_OUTPUT.PUT_LINE('b = ' || b);
    end loop;

end;
/

declare
    v1 integer := 1;
    v2 integer;

begin
    while v1 < 3
    loop
        DBMS_OUTPUT.PUT_LINE('v1 = ' || v1);
        v2 := 2 ;
        loop
            DBMS_OUTPUT.PUT_LINE('v1 = ' || v2);
            v2 := v2 + 1;
            exit  when v2 >= 2;
        end loop;
        v1 := v1 + 1;
    end loop;
end;
/


declare 
    vr employees%ROWTYPE;
    tax number := 0;
begin
    select *
    into vr
    from employees
    where employee_id = &ID;

    tax := (12*(vr.salary+vr.salary*nvl(vr.commission_pct,0)))*.1;
    dbms_output.put_line('TAX: ' || tax);
    -- set verify off ( to off the old new row)
end;
/

declare 
    cursor zip is
    select *
    from employees;
    vr zip%ROWTYPE;
begin 
    open zip;
    loop 
    fetch zip into vr;
    exit when zip%notfound;

    dbms_output.put_line(vr.employee_id);
    end loop;
end;
/

create table new (
    name varchar(50),
    id varchar(100),
    salary number(10,2)
);


set serveroutput on;
declare 
    cursor zip is
    select first_name, employee_id, salary 
    from employees
    where first_name like '__n%';

    vr zip%ROWTYPE;
begin 
    open zip;

    loop 
    fetch zip into vr;

    insert into new (name, id, salary) values(vr.employee_id , vr.first_name , vr.salary);
    dbms_output.put_line(vr.employee_id || vr.first_name || vr.salary);

    exit when zip%notfound;

    end loop;
end;
/




even odd using loop
declare 
    a integer := 0;
begin
    for a in 0..10
    loop
        if mod(a,2) = 0 then 
            dbms_output.put_line('Even: ' || a);
        else
            dbms_output.put_line('Odd: ' || a);
        end if;
    end loop;
end;
/

set serveroutput on;
set verify off;
declare
    a number(10) := &a;
begin
    
        if mod(a, 2) = 0 then 
            dbms_output.put_line('Even: ' || a);
        else 
            dbms_output.put_line('Wrong input');
        end if;
    
end;
/