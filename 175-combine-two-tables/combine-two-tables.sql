# Write your MySQL query statement below
select a.firstName,a.lastName,b.city,b.state from Person as a left join Address as b on a.personId = b.personId;

-- # Write your MySQL query statement below
-- select a.firstName, a.lastName, b.city, b.state from person a, address b
-- where a.personId = b.personId
-- inner join person;