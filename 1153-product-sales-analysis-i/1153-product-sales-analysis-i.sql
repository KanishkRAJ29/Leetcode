# Write your MySQL query statement below
SELECT
Product.product_name,Sales.year,Sales.price
FROM Product right join Sales 
on
Sales.product_id=Product.product_id
