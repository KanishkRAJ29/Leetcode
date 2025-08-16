# Write your MySQL query statement below
SELECT P.project_id,IFNULL(
    round(
        Avg(E.experience_years)
    ,2)
,0) as average_years 
from Project P
Left join Employee E
on P.employee_id =E.employee_id 
group by P.project_id  