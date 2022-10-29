drop table task;

create table task(
    id varchar(50),
    name varchar(50),
    region_name varchar(50),
    country_name varchar(50),
    cities varchar(50),
    dept_name varchar(50),
    jobs_title varchar(50),
    annual_salary number(10,2)
);

set serveroutput on;
declare
    -- define cursor
    cursor c_zip is

    -- query
    select employees.employee_id, employees.last_name, regions.region_name, countries.country_name, locations.city, departments.department_name, jobs.job_title, (12*(employees.salary+employees.salary*nvl(employees.commission_pct,0)))*.1 as salary
    from employees, regions, countries, locations, departments, jobs
    where locations.location_id = departments.location_id and employees.department_id = departments.department_id and departments.manager_id = employees.manager_id and locations.country_id = countries.country_id and regions.region_id = countries.region_id and jobs.job_id = employees.job_id;
    
    -- cursor variable type
    vr c_zip%ROWTYPE;

begin
    open c_zip;

    loop
        fetch c_zip into vr;

        insert into task values (vr.employee_id, vr.last_name, vr.region_name, vr.country_name, vr.city, vr.department_name, vr.job_title, vr.salary);
        dbms_output.put_line(vr.employee_id || vr.last_name || vr.region_name || vr.country_name || vr.city || vr.department_name || vr.job_title || vr.salary);
        exit when c_zip%notfound;
    end loop;
    
end;
/
