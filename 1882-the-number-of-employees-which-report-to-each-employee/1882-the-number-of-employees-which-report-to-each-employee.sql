# Write your MySQL query statement below
SELECT E1.employee_id ,E1.name
,(COUNT(*)) as reports_count 
, round(SUM(E2.age)/COUNT(*),0) as average_age 
from Employees E1
join Employees E2
on E1.employee_id =E2.reports_to
GROUP BY E1.employee_id, E1.name
HAVING COUNT(E2.employee_id) > 0
order by employee_id
