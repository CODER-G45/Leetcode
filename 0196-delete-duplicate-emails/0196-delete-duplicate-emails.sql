# Write your MySQL query statement below
-- SELECT email as Email
-- FROM Person
-- GROUP BY email
-- HAVING COUNT(*) > 1;

delete p1
from Person p1
join Person p2
on p1.email = p2.email
and p1.id > p2.id;