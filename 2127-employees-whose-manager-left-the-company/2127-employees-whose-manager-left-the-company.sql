# Write your MySQL query statement below
SELECT employee_id  from Employees 
where salary <30000 and manager_id NOT IN(
    SELECT employee_id from Employees
)
order by employee_id