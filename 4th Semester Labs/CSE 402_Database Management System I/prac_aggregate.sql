-- --total assest in each city
-- select branch_city, sum(assests)
-- from branch
-- group by branch_city;

-- --total branch in each city
-- select branch_city, count(branch_name) as Branch_Count
-- from branch
-- group by branch_city;

--- BANK EXAMPLE QUERIES ---
-- -- [ Find the names of all branches that have greater assets than some branch located in Brooklyn]
-- select distinct t.branch_name, t.assests 
-- from branch t, branch s 
-- where t.assests > s.assests and s.branch_city='Brooklyn';

-- -- [Find all customers who have a loan, an account, or both (Way 1)]
-- (select customer_name from depositor) 
-- union
-- (select customer_name from borrower);

-- -- [Find all customers who have "both" an account and a loan at the bank.]
-- select distinct customer_name 
-- from borrower
-- where customer_name in (
--     select customer_name
--     from depositor
-- );

-- -- [ Find all customers who have a loan at the bank but do not have an account at the bank]
-- select distinct customer_name 
-- from borrower
-- where customer_name not in (
--     select customer_name
--     from depositor
-- );

-- -- [ Find all customers who have an account at the bank but do not have a lone]
-- select distinct customer_name 
-- from depositor
-- where customer_name not in (
--     select customer_name
--     from borrower
-- );

-- -- [Find the number of depositors for each branch.]
-- select branch_name, count (distinct customer_name)
-- from depositor, account
-- where depositor.account_number = account.account_number
-- group by branch_name;

-- select distinct customer_name 
-- from borrower, loan 
-- where borrower.loan_number = loan.loan_number and
-- branch_name='Perryridge' and
-- (branch_name, customer_name) in 
-- (select branch_name, customer_name
-- from depositor, account
-- where depositor.account_number = account.account_number);


-- [NEW PRACTICE]
drop table buyer;
drop table item;

create table buyer (
    customer_id number(10),
    name varchar(50),
    country varchar(50)
);

create table item (
    order_id number(10),
    product varchar(50),
    customer_id number(10)
);

insert into buyer values (1,'Jhon','USA');
insert into buyer values (2,'Robert','USA');
insert into buyer values (3,'David','UK');
insert into buyer values (4,'John','UAE');
insert into buyer values (5,'Betty','UK');

insert into item values (88, 'Keyboard', 4);
insert into item values (89, 'Mouse', 4);
insert into item values (95, 'Monitor', 3);
insert into item values (44, 'Keyboard', 1);
insert into item values (52, 'Mousepad', 4);



select buyer.country Country, count(item.order_id) as PRODUCT
from buyer, item
where buyer.customer_id = item.customer_id
group by buyer.country
having count(order_id) = (
SELECT *
  FROM (
        select count(order_id) 
        from buyer, item 
        where buyer.customer_id = item.customer_id 
        group by buyer.country 
        order by count(order_id) desc
       )
WHERE rownum = 1
);




