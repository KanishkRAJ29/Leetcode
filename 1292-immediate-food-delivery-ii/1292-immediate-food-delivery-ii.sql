# Write your MySQL query statement below
SELECT 
ROUND(SUM(CASE WHEN order_date = customer_pref_delivery_date THEN 1 ELSE 0 END)*100/COUNT(DISTINCT customer_id),2)
as 
immediate_percentage 
from Delivery
where(customer_id,order_date) IN(
    SELECT customer_id,MIN(order_date)AS first_order_date
    from Delivery
    GROUP BY customer_id
) 
