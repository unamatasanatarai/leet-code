# Write your MySQL query statement below
SELECT c.name as Customers 
FROM Customers AS c 
  LEFT JOIN Orders o 
  ON c.id = o.customerId 
WHERE o.customerId IS NULL
