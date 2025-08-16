# Write your MySQL query statement below


# Write your MySQL query statement below
SELECT
EmployeeUNI.unique_id, Employees.name
FROM Employees
LEFT JOIN EmployeeUNI on Employees.id = EmployeeUNI.id

/*i did:-   SELECT unique_id,name from Employees
Right  Join 
EmployeeUNI on Employees.id=EmployeeUNI.id
*/