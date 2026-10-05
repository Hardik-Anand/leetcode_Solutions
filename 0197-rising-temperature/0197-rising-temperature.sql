# Write your MySQL query statement below
select w1.id from Weather as w1 inner join Weather as w2 
on 
w1.temperature > w2.temperature and datediff(w1.recordDate,w2.recordDate)=1;
