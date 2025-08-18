# Write your MySQL query statement below
SELECT * FROM patients WHERE conditions LIKE '% DIAB1%'  or conditions LIKE 'DIAB1%'

#SELECT * FROM patients WHERE conditions REGEXP '\\bDIAB1'