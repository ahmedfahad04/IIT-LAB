### Relational Database Scalinng

#### Master-Slave Replication Technique

**Master-Slave Replication** is a technique used to scale a relational database by creating copies of the main database (master) called slaves. Here's a simple explanation with an example:

- Imagine you have a popular online store where customers make orders.
- You set up a master database that handles all order processing.
- To reduce the workload on the master and improve performance, you create multiple slave databases.
- Each slave database is an exact copy of the master but read-only.
- When customers want to view products or check order status, they connect to a slave.
- When they place an order, it goes to the master for writing.

Example:
- You have an online store with a master database in New York.
- You set up two slave databases, one in London and one in Tokyo.
- Customers in Europe connect to the London slave for faster product browsing.
- Customers in Asia connect to the Tokyo slave for similar reasons.
- When they make purchases, the data is written to the master in New York, ensuring data consistency.

This way, master-slave replication helps distribute read-heavy workloads and improves the overall performance and availability of your database system.
