select subtable.customer_id, count(*) as count_no_trans from (select v.customer_id as customer_id from  Visits as v left join Transactions as t on t.visit_id = v.visit_id where t.transaction_id IS NULL) as subtable group by customer_id;


# select v.customer_id,t.transaction_id as customer_id from  Visits as v left join Transactions as t on t.visit_id = v.visit_id;