# Write your MySQL query statement below
SELECT DISTINCT(i1.num)as ConsecutiveNums
FROM Logs i1,
    Logs i2,
    Logs i3
WHERE 
    i2.id=i1.id+1 AND
    i3.id=i2.id+1 AND
    i1.num=i2.num AND
    i2.num=i3.num;
