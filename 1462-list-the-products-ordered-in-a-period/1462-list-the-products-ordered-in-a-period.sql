# Write your MySQL query statement below
SELECT p.product_name, 
       (SELECT SUM(o.unit)
        FROM Orders o
        WHERE o.product_id = p.product_id 
          AND o.order_date BETWEEN '2020-02-01' AND '2020-02-29'
       ) AS unit
FROM Products p
WHERE (SELECT SUM(o.unit)
       FROM Orders o
       WHERE o.product_id = p.product_id 
         AND o.order_date BETWEEN '2020-02-01' AND '2020-02-29'
      ) >= 100;
