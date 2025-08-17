# Write your MySQL query statement below
SELECT activity_date  as day        
,(count(distinct user_id )) as active_users 
from Activity 
where activity_date between  DATE_SUB('2019-07-27',INTERVAL 29 DAY) and '2019-07-28'
group by activity_date