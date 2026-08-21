-- # Write your MySQL query statement below
-- SELECT
--     p.firstName,
--     p.lastName,
--     a.city,
--     a.state
-- FROM Person p
-- LEFT JOIN Address a
-- ON p.personId = a.personId;
# Write your MySQL query statement below
-- select
--     c.name
-- from Customers c
-- LEFT JOIN Orders O
-- ON c.id = O.customerId;
-- where O.customerId is NULL;
SELECT c.name as Customers
FROM Customers c
LEFT JOIN Orders o
ON c.id = o.customerId
WHERE o.customerId IS NULL;