/*

CREATE TABLE prac1 (
	name varchar(50),
	phone varchar(15),
	varsity varchar(50)
);

----- REMEMBER: You must use single quote in between values parameter ------

INSERT INTO prac1 (name, phone) VALUES ('Ahmed', '0176610087');
INSERT INTO prac1 (name, phone) VALUES ('Fahad', '0176610084');
INSERT INTO prac1 (name, phone) VALUES ('Istiaq', '017661013');
INSERT INTO prac1 (name, phone) VALUES ('Istiaq', '017666713');
INSERT INTO prac1 (name, phone) VALUES ('Istiaq', '017666113');

----- CREATE table from another table ------

CREATE TABLE prac2 AS 
SELECT * 
FROM prac1 
WHERE name = 'Istiaq';

*/

---- SELECT DISTINCT element from a table -----

SELECT DISTINCT * FROM prac1;