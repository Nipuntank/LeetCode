# Write your MySQL query statement below
select u.unique_id as unique_id,e.name as name 
FROM Employees e LEFT JOIN EmployeeUNI u
on e.id=u.id;