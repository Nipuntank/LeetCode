# Write your MySQL query statement below
SELECT x,y,z,
case WHEN (x+y)>z AND (y+z)>x AND (x+z)>y THEN 'Yes' ELSE 'No' end
as triangle
FROM Triangle;
