# Write your MySQL query statement below
SELECT S.user_id,
       ROUND(
         IFNULL(
           (SELECT COUNT(*) 
            FROM Confirmations C 
            WHERE C.action = 'confirmed' 
              AND C.user_id = S.user_id) 
           /
           NULLIF(
             (SELECT COUNT(*) 
              FROM Confirmations C 
              WHERE C.user_id = S.user_id), 0
           )
         , 0)
       , 2) AS confirmation_rate
FROM Signups S;
