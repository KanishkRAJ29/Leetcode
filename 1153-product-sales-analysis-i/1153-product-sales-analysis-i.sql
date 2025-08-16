# Write your MySQL query statement below
/*SELECT
Product.product_name,Sales.year,Sales.price
FROM Product inner join Sales 
on
Sales.product_id=Product.product_id
*/
SELECT
Product.product_name,Sales.year,Sales.price
FROM Sales left join Product 
on
Sales.product_id=Product.product_id
/*i did left join*/