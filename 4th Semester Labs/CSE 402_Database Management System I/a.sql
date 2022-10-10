--select last_name || '''s salary is: ' as NAME, salary, 12*(salary+salary*nvl(commission_pct,0)) as Cumulative_Salary from employees;
--select * from TAB;
--SELECT LAST_NAME, 12*SALARY AS SALARY FROM EMPLOYEES WHERE LAST_NAME LIKE '__n%' AND 12*SALARY >= 5000;
--SELECT LAST_NAME, SALARY*12 AS ANNUAL_SALARY FROM EMPLOYEES WHERE SALARY*12 > 50000;
--SELECT LAST_NAME, DEPARTMENT_ID, 12*SALARY AS SALARY FROM EMPLOYEES ORDER BY DEPARTMENT_ID, 12*SALARY DESC;
--SELECT EMPLOYEE_ID, LAST_NAME, JOB_ID FROM &EMPLOYEES WHERE JOB_ID = '&job_name';
--SELECT EMPLOYEE_ID, LAST_NAME, JOB_ID FROM &EMPLOYEES WHERE JOB_ID = '&job_name' ORDER BY &GIVEN_ORDER;
--SELECT LAST_NAME, 12*SALARY AS SALARY, &&COL_NAME FROM EMPLOYEES WHERE 12*SALARY > 50000 ORDER BY &COL_NAME;
--select last_name || ' who''s id is ' as User, employee_id || ' and his salary is: ' as data ,salary as info from employees where employee_id=&employee_num;
--SELECT FIRST_NAME||' '||LAST_NAME||'''s "annual" salary is '||(SALARY+SALARY*nvl(COMMISSION_PCT,0))*12 "RELATION"   FROM EMPLOYEES;
-- SELECT FIRST_NAME||' '||LAST_NAME AS SALARY, SALARY*12 AS "ANNUAL SALARY" FROM EMPLOYEES;
--SELECT first_name||' '||last_name, salary FROM EMPLOYEES WHERE FIRST_NAME NOT LIKE '__s%';
--SELECT first_name||' '||last_name as NAME, salary from employees where first_name like '%sampad%' or where last_name like '%sampad%';
--SELECT first_name, department_id, salary*12 as annual_salary from employees ORDER BY department_id, salary*12 desc;
--SELECT FIRST_NAME||' '||LAST_NAME FROM EMPLOYEES WHERE FIRST_NAME ="sampad" OR LAST_NAME = "sampad";
--SELECT FIRST_NAME||' '||LAST_NAME AS NAME, SALARY FROM EMPLOYEES WHERE EMPLOYEE_ID=&EMPLOYEE_ID_INPT;
--SELECT FIRST_NAME||' '||LAST_NAME AS NAME, SALARY FROM EMPLOYEES WHERE &CONDITION ORDER BY &GIVEN_ORDERING;
--SELECT FIRST_NAME||' '||LAST_NAME AS NAME, SALARY, &row FROM employees where row LIKE &regex ORDERED BY row DESC

---SELECT * from employees;
---select lower('SQL Course') from dual;
---select first_name from employees where upper(substr(first_name, 1, 3))='JON';
---select first_name from employees where length(first_name)=6;
---select first_name, lpad(salary, 7, '*') as salary from employees;
---select first_name, rpad(salary, 7, '^') as salary from employees;
---select first_name from employees where instr(first_name,'s')=3;
---select trim(first_name), lpad(salary, 7, '*') as salary from employees;
---select concat(concat(first_name,' '), last_name) as name,lpad(salary, 10, '*') as salary from employees where substr(lower(first_name),1,3)='she';

---select concat(concat(first_name,' '), last_name) as name,lpad(salary, 10, '*') as salary from employees where instr(lower(first_name),'s')=1 and instr(lower(first_name),'h')=2 and instr(lower(first_name),'e')=3;

---select concat(concat(first_name,' '), last_name) as name, rpad(lpad(salary, 10, 'L'), 20, 'R') as salary from employees where lower(substr(first_name, 1,3))='she';
---select concat(first_name,last_name) as name, salary from employees where length(concat(first_name, last_name))=6;

---select first_name, trim('h' from lower(first_name)) as trimmed_name from employees where first_name like '%h%' or first_name like '%H%';
---select trim('d' from 'helloworld') from dual;

---select first_name, sysdate-hire_date as "Turn Around Time(days)" from employees;

---define days_at_work= 25*365;
---select first_name, sysdate-hire_date as "Less than days &days_at_work" from employees where sysdate-hire_date > &days_at_work;
---unset days_at_work

/*
define years=round((sysdate-hire_date)/365,0)
define months=abs(round(((sysdate-hire_date)/365-&years)*12,0))
define days=abs(round(sysdate-hire_date-&years*365-&months*12))
select first_name, &years as "Year", &months as "Month", &days as "Days" from employees;
*/


define years=trunc((sysdate-hire_date)/365)
define extra_days=mod(sysdate-hire_date,365)
define months=trunc(&extra_days/30)
define days=trunc(&extra_days-&months*30)

select first_name, &years as "Years", &months as "Month", &days as "Days" from employees;


/*

--create or replace procedure raise_salary(
--p_id IN employees.employee id%TYPE,
--p_percent IN Number)
--IS 
--BEGIN
--UPDATE EMPLOYEES
--set salary = salary * (1 + p_percent/100)
--Where employee_id = p_id;
--END raise_salary;
--/
*/


/*
create or replace procedure query_emp(
p_id IN emplloyees.employee id%Type,
p_name OUT empoyees.employee name%Type,
p_salary OUT employees.salary salary%Type) IS

BEGIN
	SELECT last_name, salary into p_name, p_salary
	FROM employees
	WHERE EMPLOYEE_ID = P_ID;
END query_emp;
/

DECLARE
v_emp_name employees.last_name%Type;
v_emp_sal employees.salary%Type;

begin
	query_emp(171, v_emp_name, v_emp_sal);
	dbms_output_put_line(v_emp_name || ' earns ' || to_char(v_emp_sal, $999,999.0));
end;
/

*/



/*

create or replace procedure formate_phone
(p_phone_no IN OUT VARCHAR2) IS

begin
	p_phone_no := '(' || SUBSTR(p_phone_no,1,3) || ')' || SUBSTR(p_phone_no,4,3) ||  '-' || SUBSTR(p_phone_no, 7);
EMD;
/

declare
	v_num(12);

begin
	v_num := '01766610087';
	formate_phone(v_num);
	dbms_output.put_line(v_num);
end;
/





create table mydata 
(
	ID varchar(15),
	phone varchar(11),
	
);

insert into mydata (id, phone) values(1, '0176610087');
insert into mydata (id, phone) values(2, '0176610088');
insert into mydata (id, phone) values(3, '0176610089');
insert into mydata (id, phone) values(4, '0176610077');
insert into mydata (id, phone) values(5, '0176610067');

create table mydata2
(
	ID varchar(15),
	phone varchar(11),
	
);


create or replace procedure updatedData(
p_id IN mydata.id%Type,
p_phone IN OUT mydata.phone%Type) IS

BEGIN
	SELECT id, phone into p_id, p_phone
	FROM mydata
	WHERE ID = p_id;


	p_phone := '(' || SUBSTR(p_phone,1,3) || ')' || SUBSTR(p_phone,4,3) ||  '-' || SUBSTR(p_phone, 7);

END;
/



declare
	v_num varchar(12);
	p_id varchar(15);

begin
	p_id := 1;

	--v_num := p_phone;
	--formate_phone(v_num);

	--dbms_output.put_line(v_num);


	updatedData(p_id, p_phone);
	insert into mydata2(p_id, p_phone);
end;
/



*/