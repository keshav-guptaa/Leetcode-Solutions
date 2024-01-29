# Write your MySQL query statement below
SELECT s.machine_id, Round(AVG(e.timestamp - s.timestamp), 3) AS processing_time
FROM Activity s, Activity e
WHERE s.activity_type = "start" AND e.activity_type = "end" AND s.machine_id = e.machine_id
GROUP BY machine_id;