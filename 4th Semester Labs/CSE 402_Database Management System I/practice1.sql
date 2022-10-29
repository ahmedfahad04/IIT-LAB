-- Chapter 1 Exercise Solution (Salesman table skipped...) --


/*
CREATE TABLE Client_master (
	client_no varchar2(6),
	name varchar2(20),
	address1 varchar2(20),
	address2 varchar2(30),
	city varchar2(30),
	pincode number(15),
	state varchar2(8),
	bal_due number(10,2)
);




CREATE TABLE product_master ( 
	product_no varchar2(6),
	description varchar2(15),
	profit_present number(4,2),
	unit_measure varchar2(10),
	qty_on_hand number(8),
	reorder_lvl number(8),
	sell_price number(8,2),
	cost_price number(8,2)
);



CREATE TABLE new_client
	(client_no, name, city, pincode, state, bal_due) 
	AS SELECT client_no, name, city, pincode, state, bal_due
	FROM Client_master;


---------- IMPORTANAT: Changing CELL VALUE -> UPDATE, Changing COLUMN DATATYPE and SIZE -> ALTER ----------

alter table new_client
modify(name varchar(50));

alter table new_client;
modify(state varchar(50));

alter table client_master;
modify(name varchar2(50));

alter table client_master;
modify(state varchar2(50));



INSERT INTO client_master (client_no, name, city, pincode, state, bal_due) 
VALUES ('C00001', 'Fahad', 'Bombay', 400054, 'Maharastra', 15000);

INSERT INTO client_master (client_no, name, city, pincode, state, bal_due) 
VALUES ('C00002', 'Vandana Saitwal', 'Madras', 780001, 'Tamil Nadu', 0);

INSERT INTO client_master (client_no, name, city, pincode, state, bal_due) 
VALUES ('C00003', 'Pramada Jaguste', 'Bombay', 400057, 'Maharastra', 5000);

INSERT INTO client_master (client_no, name, city, pincode, state, bal_due) 
VALUES ('C00004', 'Basu Navindgi', 'Bombay', 400056, 'Maharastra', 0);

INSERT INTO client_master (client_no, name, city, pincode, state, bal_due) 
VALUES ('C00005', 'Ravi Sreedharen', 'Delhi', 100001, 'Maharastra', 2000);

INSERT INTO client_master (client_no, name, city, pincode, state, bal_due) 
VALUES ('C00006', 'Rukmini', 'Bombay', 400050, 'Bombay', 0);



------- TECHNIQUE: To remove all rows we may obtain many techiniqe, here I just put a specific condition to select all the rows --------
delete from new_client where bal_due < 17000; 


INSERT INTO product_master (product_no, description, profit_present, unit_measure, qty_on_hand, reorder_lvl, sell_price, cost_price) 
VALUES ('P00001', '1.44 Floppies', 5, 'Piece', 100, 20, 525, 500);

INSERT INTO product_master (product_no, description, profit_present, unit_measure, qty_on_hand, reorder_lvl, sell_price, cost_price) 
VALUES ('P00002', 'Monitors', 5, 'Piece', 100, 20, 525, 500);

INSERT INTO product_master (product_no, description, profit_present, unit_measure, qty_on_hand, reorder_lvl, sell_price, cost_price) 
VALUES ('P00003', 'Mouse', 5, 'Piece', 100, 20, 525, 500);

INSERT INTO product_master (product_no, description, profit_present, unit_measure, qty_on_hand, reorder_lvl, sell_price, cost_price) 
VALUES ('P00004', '1.22 Floppies', 5, 'Piece', 100, 20, 525, 500);

INSERT INTO product_master (product_no, description, profit_present, unit_measure, qty_on_hand, reorder_lvl, sell_price, cost_price) 
VALUES ('P00005', 'Keyboards', 5, 'Piece', 100, 20, 525, 500);

INSERT INTO product_master (product_no, description, profit_present, unit_measure, qty_on_hand, reorder_lvl, sell_price, cost_price) 
VALUES ('P00006', 'CD Drive', 5, 'Piece', 100, 20, 525, 500);

INSERT INTO product_master (product_no, description, profit_present, unit_measure, qty_on_hand, reorder_lvl, sell_price, cost_price) 
VALUES ('P00007', '540 HDD', 5, 'Piece', 100, 20, 525, 500);

INSERT INTO product_master (product_no, description, profit_present, unit_measure, qty_on_hand, reorder_lvl, sell_price, cost_price) 
VALUES ('P00008', '1.44 Drive', 5, 'Piece', 100, 20, 525, 500);

INSERT INTO product_master (product_no, description, profit_present, unit_measure, qty_on_hand, reorder_lvl, sell_price, cost_price) 
VALUES ('P00009', '1.22 Drive', 5, 'Piece', 100, 20, 525, 500);


------3rd question-----
select name from client_master;
select * from client_master;
select name, city from client_master;

select description from product_master;
select name from client_master where city='Bombay';

-- last question skipped --


*/
------4th question-----
--update client_master set city='Bombay' where client_no='C00005';
--update client_master set bal_due=1000 where client_no='C00001';
--update product_master set cost_price=950 where description='1.22 Floppies';
--d skipped --

-------5th Question-----
--a skipped --
--delete from product_master where qty_on_hand=100;
--delete from client_master where state='Tamil Nadu';


-------6th Question-----
-- alter table client_master add(telephone number(10));
-- alter table product_master modify(sell_price number(10,2));

--------7th Question------
-- drop table client_master;


---------8th Question-------
-- rename product_master to products_master;