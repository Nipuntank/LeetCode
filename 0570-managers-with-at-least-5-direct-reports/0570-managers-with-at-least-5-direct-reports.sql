# Write your MySQL query statement below
select e.name
from Employee as e
INNER JOIN Employee as m on e.id=m.managerId
GROUP BY m.managerId
HAVING COUNT(m.managerId)>=5;
