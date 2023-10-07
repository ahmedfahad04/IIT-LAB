### Relational Database Scalinng

#### Master-Slave Replication Technique

> To handle HUGE writes than reads

It's a technique used to scale a relational database by creating copies of the main database (master) called slaves. Here's a simple explanation with an example:

- Imagine you have a popular `online store` where customers make orders.
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

#### Master-Master Replication Technique (to handle HIGH AVAILABILITY)

> To handle HIGH AVAILABILITY

It's another technique used to scale a relational database, but it allows **_both database servers to act as both a master and a slave_** simultaneously. In this setup, both servers can accept both read and write operations, making it suitable for scenarios where high availability and load balancing are critical.

Here's a brief explanation with an example:

- Imagine you have a `global messaging` application, and you want to ensure it's highly available.
- You set up two database servers, Server A and Server B, in different data centers.
- Both Server A and Server B can accept both read and write requests.
- When a user in the United States sends a message, it can be written to Server A.
- Simultaneously, when a user in Europe sends a message, it can be written to Server B.
- Both servers periodically **synchronize** data changes between each other to ensure consistency.

Example:

- User A in the United States sends a message to User B.
- Server A records the message locally.
- Server B also records the message, keeping both databases up-to-date.
- If Server A goes down for maintenance or due to an issue, Server B can still handle read and write operations for all users, ensuring high availability.

Master-master replication is complex to set up and manage due to the need for data conflict resolution and synchronization mechanisms, but it offers improved redundancy and load balancing capabilities for critical applications.

### Federation (to handle HUGE users)

> To handle HUGE users

It's a database scaling technique where data is **distributed** across multiple independent databases, each handling a specific subset or shard of the overall data. It's commonly used in scenarios where data can be **_logically partitioned_**, such as **social media platforms**, where users' data can be distributed based on their geographical location or some other criteria.

Federation (or functional partitioning) **splits up databases by function**. For example, instead of a single, monolithic database, you could have three databases: forums, users, and products, resulting in less read and write traffic to each database and therefore less replication lag.

Here's a simplified explanation:

- Imagine you run a social media platform with millions of users.
- Instead of storing all user data in a single massive database, you create smaller, independent databases or shards.
- Each shard contains the data for a specific group of users, like those from a particular city or state.
- When a user interacts with the platform, their data is stored in the appropriate shard.
- Queries for data related to a specific group of users are directed to the relevant shard, reducing the load on any single database.

Example:

- For a social media platform, you might have different database shards for users in New York, Los Angeles, and Chicago.
- Users in New York primarily interact with the New York shard, while users in Los Angeles use the Los Angeles shard.
- This approach ensures that database queries and updates are distributed across multiple servers, improving performance and scalability.

Federation allows you to efficiently manage large amounts of data by dividing it into manageable pieces, which can be especially useful for applications with a massive user base.

### Sharding

> To handle HIGH DATA THROUGHPUT

It's a database scaling technique used to distribute data across multiple independent database servers or **"shards."** Each shard holds a portion of the overall dataset, and this approach helps improve database performance and scalability, particularly in scenarios with large amounts of data or high data **throughput** requirements.

Sharding distributes data across different databases such that each database can only manage a subset of the data. Taking a users database as an example, **_as the number of users increases, more shards are added to the cluster._**

Here's a simplified explanation:

- Imagine you have a massive online retail platform with millions of products.
- Instead of storing all product data in a single database, you divide the products into categories.
- Each category (e.g., electronics, clothing, books) becomes a shard, and you store its data in a separate database server.
- When a customer searches for electronics, the query goes to the electronics shard, not the entire database.
- Queries and updates are distributed across multiple shards, reducing the load on any single database server.

Example:

- For an e-commerce website, you might shard your databases based on product categories like electronics, clothing, and books.
- Each shard (database server) handles data for its category only.
- When a customer looks for electronics, the search query is directed to the electronics shard for faster results.

Sharding allows you to scale your database horizontally, ensuring that your application can handle a growing amount of data and a high volume of transactions efficiently. It's commonly used in **large-scale web applications and services.**

##### Diff with Federation

- In terms of **Sharding**, it splits a SINGLE FUNCTIONAL DB (like USER DB/Product DB) into multiple
  shards. On the other hand, **Federation** splits the WHOLE DB into different shards based on the
  FUNCTIONALITY.

- Sharding try to scale a specific Database, while Federation tries to scale the whole Database.

- Like federation, there is no single central master serializing writes, allowing you to write in parallel with increased throughput.
