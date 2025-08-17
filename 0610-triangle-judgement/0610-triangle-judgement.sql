# Write your MySQL query statement below
SELECT x,y,z,(case when (x+y)>z AND (x+z)>y and (y+z)>x THEN 'Yes' ELSE 'No' END) as triangle 
from Triangle 