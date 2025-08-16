# Write your MySQL query statement below
SELECT * from Cinema
where Cinema.id%2=1 and description !="boring"
ORDER BY rating DESC