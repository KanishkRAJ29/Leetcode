# Write your MySQL query statement below
SELECT 
LEFT(trans_date,7) as month
,country
,count(id)As trans_count
,Sum(state='approved')AS approved_count
,Sum(amount)AS trans_total_amount
,Sum((state='approved')*amount)As approved_total_amount
from 
Transactions
group by 
month,country
