# Write your MySQL query statement below
select name from Customer where referee_id IS NULL or not referee_id = 2;