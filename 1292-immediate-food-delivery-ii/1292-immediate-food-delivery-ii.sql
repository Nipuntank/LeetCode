# Write your MySQL query statement below
SELECT ROUND(AVG(d.order_date=d.customer_pref_delivery_date)*100,2) as immediate_percentage
FROM Delivery d
INNER JOIN (
    SELECT customer_id,MIN(order_date) first_order_date
    FROM Delivery
    GROUP BY customer_id
    )first_order
ON d.customer_id=first_order.customer_id AND d.order_date=first_order.first_order_date;
    