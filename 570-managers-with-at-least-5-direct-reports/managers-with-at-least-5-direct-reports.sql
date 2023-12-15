SELECT name FROM Employee WHERE id IN (SELECT managerId FROM Employee GROUP BY managerId having count(*)>=5 ) ;

# SELECT managerId FROM Employee GROUP BY managerId having count(*)>=5