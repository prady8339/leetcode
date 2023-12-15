# Write your MySQL query statement below
select s.user_id, COALESCE(calc.confirmation_rate, 0) AS confirmation_rate from 
Signups s
left join
(select 
treq.user_id,
round( creq.c_req / treq.total_request, 2) as confirmation_rate from 
(select user_id , count(*) as c_req from Confirmations where action = 'confirmed' group by user_id) as creq
inner join
(select user_id , count(*) as total_request from Confirmations group by user_id) as treq
on creq.user_id = treq.user_id) as calc
on s.user_id = calc.user_id;
