-- [slide 39, chapt-3]

-- insert into account (
--     select loan_number, branch_name, amount+200
--     from loan 
--     where branch_name='Perryridge'
-- ); 
-- insert into depositor (
--     select customer_name, loan.loan_number
--     from loan, borrower 
--     where branch_name='Perryridge' and
--     loan.loan_number = borrower.loan_number
-- );

-- [NOTE-1] ==> If try to delete any record from a table which has constraint of foreign key, it must be removed through alter.
-- alter table loan
-- drop CONSTRAINT loan_branch_branchName_fk;
-- alter table borrower 
-- drop CONSTRAINT borrower_AccountNumber_FK;

-- delete from loan
-- where branch_name='Perryridge';



-- Temp table that stores the max value
-- create or replace view max_balance as (select min(balance) as bal from account);

-- select account_number, account.balance
-- from account, max_balance
-- where account.balance = max_balance.bal;

--***
    -- create view count_course as (select studentID, count(course#) as cnt from enroll group by studentID);
    -- create view mx_cnt as (select studentID, max(cnt) as m_cnt from count_course group by studentID);

--     select student_id
--     from enroll, mx_cnt  
--     group by student_id
--     having count(course#) = mx_cnt.m_cnt ;

