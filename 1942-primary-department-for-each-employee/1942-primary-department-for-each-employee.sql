SELECT employee_id, department_id
FROM Employee
GROUP BY employee_id, department_id
HAVING MAX(primary_flag = 'Y') = 1 OR COUNT(*) = 1;
