# Write your MySQL query statement below
SELECT name,bonus
from Employee left join Bonus
on Employee.empId=Bonus.empId
where bonus IS NULL or bonus<1000#i wrore =NULL