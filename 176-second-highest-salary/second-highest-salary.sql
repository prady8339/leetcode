select 
(select distinct salary from Employee 
order by salary desc Limit 1 offset 1)
as SecondHighestSalary