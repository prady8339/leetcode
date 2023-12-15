select e2.name from Employee e1 inner join Employee e2 on e1.managerId = e2.id group by e1.managerId having count(e1.managerId) >= 5;
