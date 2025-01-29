# Write your MySQL query statement below
select e.name as name,b.bonus as bonus
FROM Employee e LEFT JOIN bonus b
on e.empId=b.empId
WHERE b.bonus<1000 or b.bonus is null;