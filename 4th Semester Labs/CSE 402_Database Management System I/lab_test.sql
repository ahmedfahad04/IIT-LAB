-- -- EXAMPLE OF ALGEBRA QUERY --

-- remember to remove foreign keys tables before the table which is referenced as primary key (here drop RESERVE befoe SAILORS)
drop table reserve; 
drop table sailors;
drop table boats;

create table sailors(
    sid number(10),
    sname varchar(50),
    rating number(10, 2),
    age number(10, 1),
    constraint sid_pk primary key (sid)
);

create table reserve(
    sid number(10),
    bid number(10),
    day varchar(10),
    constraint bid_pk primary key (bid, sid),
    constraint sid_fk foreign key (sid) references sailors (sid)
);

create table boats(
    bid number(10),
    bname varchar(50),
    color varchar(50),
    constraint bid_pk2 primary key (bid)
);

insert into sailors (sid, sname, rating, age) values (22, 'Dustin', 7, 45.0);
insert into sailors (sid, sname, rating, age) values (29, 'Brutus', 1, 33.0);
insert into sailors (sid, sname, rating, age) values (31, 'Lubber', 8, 55.0);
insert into sailors (sid, sname, rating, age) values (32, 'Andy', 8, 25.5);
insert into sailors (sid, sname, rating, age) values (58, 'Rusty', 10, 35.0);
insert into sailors (sid, sname, rating, age) values (64, 'Horatio', 7, 35.0);
insert into sailors (sid, sname, rating, age) values (71, 'Zorba', 10, 16.0);
insert into sailors (sid, sname, rating, age) values (74, 'Horatio', 9, 35.0);
insert into sailors (sid, sname, rating, age) values (85, 'Art', 3, 25.5);
insert into sailors (sid, sname, rating, age) values (95, 'Bob', 3, 63.5);

insert into reserve (sid, bid, day) values (22, 101, '10/10/98');
insert into reserve (sid, bid, day) values (22, 102, '10/10/98');
insert into reserve (sid, bid, day) values (22, 103, '10/8/98');
insert into reserve (sid, bid, day) values (22, 104, '10/7/98');
insert into reserve (sid, bid, day) values (31, 102, '11/10/98');
insert into reserve (sid, bid, day) values (31, 103, '11/6/98');
insert into reserve (sid, bid, day) values (31, 104, '11/12/98');
insert into reserve (sid, bid, day) values (64, 101, '9/5/98');
insert into reserve (sid, bid, day) values (64, 102, '9/8/98');
insert into reserve (sid, bid, day) values (74, 103, '9/8/98');

insert into boats (bid, bname, color) values (101, 'Interlake', 'blue');
insert into boats (bid, bname, color) values (102, 'Interlake', 'red');
insert into boats (bid, bname, color) values (103, 'Clipper', 'green');
insert into boats (bid, bname, color) values (104, 'Marine', 'red');


-- -- [a. Find names of sailors who have reserved boat 103, Way 1]
-- select sailors.sname 
-- from sailors
-- natural join reserve
-- WHERE reserve.bid = 103;

-- -- [a. Way 2]
-- select sailors.sname 
-- from sailors, reserve
-- WHERE sailors.sid = reserve.sid and reserve.bid = 103;

-- -- [b. Find the names of sailors who have reserved a red boat]
-- select distinct sailors.sname
-- from sailors, boats, reserve
-- where sailors.sid = reserve.sid and reserve.bid = boats.bid and boats.color = 'red';

-- -- [c. Find the colors of boats reserved by Lubber]
-- select boats.color 
-- from boats, sailors, reserve 
-- where sailors.sid = reserve.sid and reserve.bid = boats.bid and sailors.sname = 'Lubber';

-- -- [d. Find the names of Sailors who have reserved at least one boat]
-- select distinct sailors.sname
-- from sailors, reserve
-- where sailors.sid = reserve.sid;

-- -- [d2. Find the names of Sailors who have reserved at least 2 boats]
-- select distinct sailors.sname
-- from sailors
-- where not unique (
--     select sailors.sname 
--     from sailors, reserve 
--     where sailors.sid = reserve.sid
-- );

-- -- [e. Find the names of Sailors who have reserved a red and a green boat.]
-- select distinct sailors.sname 
-- from sailors, boats, reserve
-- where sailors.sid = reserve.sid and reserve.bid = boats.bid and boats.color = 'red' 
-- intersect
-- select distinct sailors.sname 
-- from sailors, boats, reserve
-- where sailors.sid = reserve.sid and reserve.bid = boats.bid and boats.color = 'green';

-- [f. Find the names of sailors who have reserved at least 2 boats]
-- select sailors.sname as name, count(*) as reservs
-- from sailors, boats, reserve
-- where sailors.sid = reserve.sid and reserve.bid = boats.bid
-- group by sailors.sname
-- having count(*) >= 2;

-- -- [g. Find the sids of sailors with age over 20 who have not reserved a red boat. (Way 1)]
-- select distinct sailors.sid, sailors.sname, sailors.age, boats.color
-- from sailors, boats, reserve
-- where sailors.sid = reserve.sid and reserve.bid = boats.bid and sailors.age > 20
-- intersect 
-- select distinct sailors.sid, sailors.sname, sailors.age, boats.color
-- from sailors, boats, reserve
-- where sailors.sid = reserve.sid and reserve.bid = boats.bid and boats.color != 'red';

-- -- [g. Find the sids of sailors with age over 20 who have not reserved a red boat. (Way 2)]
-- select sailors.sid, sailors.sname, boats.color
-- from sailors, boats, reserve 
-- where sailors.sid = reserve.sid and reserve.bid = boats.bid and sailors.age > 20
-- minus
-- select sailors.sid, sailors.sname, boats.color
-- from sailors, boats, reserve 
-- where sailors.sid = reserve.sid and reserve.bid = boats.bid and boats.color = 'red';

-- -- [g. Find the sids of sailors with age over 20 who have not reserved a red boat. (Way 3)]
-- select distinct sailors.sid, sailors.sname, sailors.age, boats.color
-- from sailors, boats, reserve
-- where sailors.sid = reserve.sid and reserve.bid = boats.bid and boats.color != 'red' and sailors.age > 20;

-- -- [h. Find the names of sailors who have reserved all boats.]
-- select sailors.sname as name, count(*) as reservs
-- from sailors, boats, reserve
-- where sailors.sid = reserve.sid and reserve.bid = boats.bid
-- group by sailors.sname
-- having count(*) >= (
-- select distinct count(boats.bid)
-- from boats
-- );

-- -- [i. Find the names of sailors who have reserved all boats called Interlake]

-- select sailors.sid, sailors.sname, count(boats.bid)
-- from sailors, reserve, boats
-- where sailors.sid = reserve.sid and reserve.bid = boats.bid and boats.bname='Interlake'
-- group by sailors.sname, sailors.sid
-- having count(boats.bid) = (
-- select distinct count(boats.bid) 
-- from boats
-- where boats.bname = 'Interlake'    
-- );

-- [EXTRA: Find the sid and sailor names who have not reserve any boat]
-- select sailors.sid, sailors.sname
-- from sailors, boats, reserve 
-- minus
-- select sailors.sid, sailors.sname
-- from sailors, boats, reserve 
-- where sailors.sid = reserve.sid and reserve.bid = boats.bid; 

--  [OR]

-- select distinct sailors.sid, sailors.sname
-- from sailors
-- where sailors.sid != ALL (
-- select distinct sailors.sid
-- from sailors, reserve, boats
-- where sailors.sid = reserve.sid and reserve.bid = boats.bid
-- );


-- create or replace view v as 
-- select distinct count(boats.bid) as bi 
-- from boats
-- where boats.bname = 'Interlake';
