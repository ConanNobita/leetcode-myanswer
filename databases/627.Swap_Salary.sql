# Write your MySQL query statement below
UPDATE salary SET sex = (CASE sex WHEN 'f' THEN 'm' ELSE 'f' END)