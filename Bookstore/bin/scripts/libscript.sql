CREATE TABLE IF NOT EXISTS library.books
(
    book_id SERIAL NOT NULL PRIMARY KEY,
    title varchar(255),
    author varchar(255)
);
CREATE TABLE IF NOT EXISTS library.publisher
(
    pub_id SERIAL NOT NULL PRIMARY KEY,
    location varchar(255)
);
create table IF NOT EXISTS library.patrons(
phone_n VARCHAR(11),
surname VARCHAR (255),
adress VARCHAR (255),
card_num SERIAL PRIMARY KEY,
reg_date DATE
);
CREATE TABLE IF NOT EXISTS library.bookcopy
(
	copy_id SERIAL not NULL PRIMARY KEY,
    book_id integer,
	year_published date,
	pub_id integer,
	CONSTRAINT fk_publisher FOREIGN KEY (pub_id) references library.publisher(pub_id) ON UPDATE CASCADE  ON DELETE CASCADE,
	CONSTRAINT fk_book FOREIGN KEY (book_id) references library.books(book_id) ON UPDATE CASCADE  ON DELETE CASCADE 
);
create table IF NOT EXISTS library.issues(
book_id integer,
borrow_date DATE,
deadline DATE,
card_num integer,
CONSTRAINT books_fk
FOREIGN KEY (book_id)
REFERENCES library.bookcopy (copy_id),
CONSTRAINT patrons_fk
FOREIGN KEY (card_num)
REFERENCES library.patrons (card_num),
PRIMARY KEY(book_id, card_num)
);

CREATE OR REPLACE FUNCTION library.archive_book_count() returns table
(book_name varchar,count bigint) language plpgsql
as $$
begin
  return query 
    select title, count(copy_id) from library.books b join library.bookcopy bc
	on b.book_id = bc.book_id join library.archive arc
	on arc.book_id = bc.copy_id group by title;
    end;
$$;

CREATE OR REPLACE FUNCTION library.publisher_count() returns table
(book_name varchar,count bigint) language plpgsql
as $$
begin
  return query 
    SELECT location, count(bc.pub_id) FROM library.publisher pub join library.bookcopy bc on bc.pub_id = pub.pub_id
    group by location;
    end;
$$;

create or replace function foreignIssTr() returns trigger
language plpgsql
AS $$
DECLARE
bookcnt integer;
patroncnt integer;
BEGIN
select count(bc.copy_id) into bookcnt FROM library.bookcopy bc where bc.copy_id = new.book_id;
select count(pat.card_num) into patroncnt FROM library.patrons pat where pat.card_num = new.card_num;
if patroncnt = 0 then
RAISE SQLSTATE '20555';
return old;
end if;
if bookcnt = 0 then
RAISE SQLSTATE '20556';
return old;
end if;
return new;
end;
$$;

CREATE OR REPLACE FUNCTION library.debt(card integer) returns table
(book_name varchar, authors varchar) language plpgsql
as $$
begin
  return query 
    SELECT title, author from library.issues iss inner join 
  library.bookcopy bc on iss.book_id = bc.copy_id inner join 
  library.books bo on bo.book_id = bc.book_id inner join library.patrons pa 
  on iss.card_num = pa.card_num where pa.card_num=card;
    end;
$$;


create or replace trigger issueInsForeign
before insert on library.issues
for each row
execute function foreignisstr();

create or replace trigger issueUpdForeign
before update on library.issues
for each row
execute function foreignisstr();

Create or replace function fillDeadlineTR() returns trigger
language plpgsql
AS
$$
DECLARE
D date;
BEGIN
D = new.borrow_date + interval '3 months';
NEW.deadline := D;
return new;
END;
$$;

CREATE OR REPLACE TRIGGER DeadlineIns 
BEFORE INSERT on library.issues
for each roW
EXECUTE FUNCTION fillDeadLineTR();

CREATE OR REPLACE TRIGGER DeadlineUpd
BEFORE UPDATE on library.issues
for each roW
EXECUTE FUNCTION fillDeadLineTR();
