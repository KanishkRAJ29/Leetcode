# Write your MySQL query statement below
SELECT  name from Employee where 
id IN
(SELECT managerId AS id
FROM Employee
WHERE managerId IS NOT NULL
GROUP BY managerId
HAVING COUNT(*) >= 5)
