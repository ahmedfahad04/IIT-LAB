---Dropping Table
drop table BORROWER;
drop table DEPOSITOR;
drop table LOAN;
drop table ACCOUNT;
drop table BRANCH;
drop table CUSTOMER;


--- Creating Table
create table BRANCH(
	branch_name varchar(75) not null,
	branch_city varchar(50),
	assests number(20),
	constraint BRANCH_BranchName_PK PRIMARY KEY(branch_name)
);

create table CUSTOMER 
(
	customer_name varchar(75) not null,
	customer_street varchar(100),
	customer_city varchar(100),
	constraint CUSTOMER_CustomerName_PK PRIMARY KEY (customer_name)
);

create table ACCOUNT 
(
	account_number varchar(10) not null,
	branch_name varchar(75),
	balance number(6),
	constraint account_accountNumber_PK PRIMARY KEY (account_number),
	constraint account_branch_branchName_fk FOREIGN KEY (branch_name) REFERENCES BRANCH(branch_name) 
);

create table LOAN 
(
	loan_number varchar(50) not null,
	branch_name varchar(75),
	amount number(20),
	constraint LOAN_loanNumber_PK PRIMARY KEY (loan_number),
	constraint loan_branch_branchName_fk FOREIGN KEY(branch_name) REFERENCES branch (branch_name)
);

create table DEPOSITOR (
	customer_name varchar(75),
	account_number varchar(10),
	constraint depositor_CustomerName_FK FOREIGN KEY (customer_name) REFERENCES Customer(customer_name),
	constraint depositor_AccountNumber_FK FOREIGN KEY (account_number) REFERENCES Account(account_number),
	constraint depositor_composite_PK PRIMARY KEY (customer_name, account_number)
);

create table BORROWER
(
	customer_name varchar(75),
	loan_number varchar(50),
	constraint borrower_CustomerName_FK FOREIGN KEY (customer_name) REFERENCES Customer(customer_name),
	constraint borrower_AccountNumber_FK FOREIGN KEY (loan_number) REFERENCES loan(loan_number),
	constraint borrower_composite_PK PRIMARY KEY (customer_name, loan_number)
);






--- Insert Data

INSERT INTO BRANCH VALUES ('Brighton', 'Brooklyn', 7100000);
INSERT INTO BRANCH VALUES ('Downtown', 'Brooklyn', 9000000);
INSERT INTO BRANCH VALUES ('Mianus', 'Horseneck', 400000);
INSERT INTO BRANCH VALUES ('North Town', 'Rye', 3700000);
INSERT INTO BRANCH VALUES ('Perryridge', 'Horseneck', 1700000);
INSERT INTO BRANCH VALUES ('Pownal', 'Beinnington', 300000);
INSERT INTO BRANCH VALUES ('Redwood', 'Palo Alto', 2100000);
INSERT INTO BRANCH VALUES ('Round Hill', 'Horseneck', 8000000);

INSERT INTO CUSTOMER VALUES ('Adams', 'Spring','Pittsfield');
INSERT INTO CUSTOMER VALUES ('Brooks', 'Senator','Brooklyn');
INSERT INTO CUSTOMER VALUES ('Curry', 'North','Rye');
INSERT INTO CUSTOMER VALUES ('Glenn', 'Sand Hill','Woodside');
INSERT INTO CUSTOMER VALUES ('Green', 'Walnut','Stamford');
INSERT INTO CUSTOMER VALUES ('Hayes', 'Main','Harrison');
INSERT INTO CUSTOMER VALUES ('Johnson', 'Alma','Palo alto');
INSERT INTO CUSTOMER VALUES ('Jones', 'Main','Harrison');
INSERT INTO CUSTOMER VALUES ('Lindsay', 'Park','Pittsfield');
INSERT INTO CUSTOMER VALUES ('Smith', 'North','Rye');
INSERT INTO CUSTOMER VALUES ('Turner', 'Putnam','Stamford');
INSERT INTO CUSTOMER VALUES ('Williams', 'Nassau','Princeton');

INSERT INTO ACCOUNT VALUES ('A-101', 'Downtown',500);
INSERT INTO ACCOUNT VALUES ('A-102', 'Perryridge',400);
INSERT INTO ACCOUNT VALUES ('A-201', 'Brighton',900);
INSERT INTO ACCOUNT VALUES ('A-215', 'Mianus',700);
INSERT INTO ACCOUNT VALUES ('A-217', 'Brighton',750);
INSERT INTO ACCOUNT VALUES ('A-222', 'Redwood',700);
INSERT INTO ACCOUNT VALUES ('A-305', 'Round Hill',350);


INSERT INTO LOAN VALUES ('L-11', 'Round Hill',900);
INSERT INTO LOAN VALUES ('L-14', 'Downtown',1500);
INSERT INTO LOAN VALUES ('L-15', 'Perryridge',1500);
INSERT INTO LOAN VALUES ('L-16', 'Perryridge',1300);
INSERT INTO LOAN VALUES ('L-17', 'Downtown',1000);
INSERT INTO LOAN VALUES ('L-23', 'Redwood',2000);
INSERT INTO LOAN VALUES ('L-93', 'Mianus',500);

INSERT INTO DEPOSITOR VALUES ('Williams', 'A-102');
INSERT INTO DEPOSITOR VALUES ('Johnson', 'A-101');
INSERT INTO DEPOSITOR VALUES ('Johnson', 'A-201');
INSERT INTO DEPOSITOR VALUES ('Jones', 'A-217');
INSERT INTO DEPOSITOR VALUES ('Lindsay', 'A-222');
INSERT INTO DEPOSITOR VALUES ('Smith', 'A-215');
INSERT INTO DEPOSITOR VALUES ('Turner', 'A-305');

INSERT INTO BORROWER VALUES ('Adams', 'L-16');
INSERT INTO BORROWER VALUES ('Curry', 'L-93');
INSERT INTO BORROWER VALUES ('Hayes', 'L-15');
INSERT INTO BORROWER VALUES ('Johnson', 'L-14');
INSERT INTO BORROWER VALUES ('Jones', 'L-17');
INSERT INTO BORROWER VALUES ('Smith', 'L-11');
INSERT INTO BORROWER VALUES ('Smith', 'L-23');
INSERT INTO BORROWER VALUES ('Williams', 'L-17');
