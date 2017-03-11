# 197. Rising Temperature
# https://leetcode.com/problems/rising-temperature/
# 

SELECT t.Id 
FROM Weather as t 
INNER JOIN Weather as p
ON t.Date = DATE_ADD(p.Date,INTERVAL 1 DAY) 
WHERE t.Temperature > p.Temperature;

/*
Given a Weather table, write a SQL query to find all dates' Ids with higher temperature compared to its previous (yesterday's) dates. 
+---------+------------+------------------+
| Id(INT) | Date(DATE) | Temperature(INT) |
+---------+------------+------------------+
|       1 | 2015-01-01 |               10 |
|       2 | 2015-01-02 |               25 |
|       3 | 2015-01-03 |               20 |
|       4 | 2015-01-04 |               30 |
+---------+------------+------------------+
 For example, return the following Ids for the above Weather table: 
+----+
| Id |
+----+
|  2 |
|  4 |
+----+
 Subscribe to see which companies asked this question.
*/
