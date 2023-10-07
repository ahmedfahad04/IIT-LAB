### Relational Database Scalinng

There are several techniques to Scale Relational Database. Most common of those are:

- [Master-Slave Replication](#Master-Slave-Replication)
- [Master-Master Replication](#master-master-replication)
- [Federation](#federation)
- [Sharding](#sharding)
- [Denormalizing](#denormalizing)
- [SQL Tuning](#sql-tuning)

#### Master-Slave Replication

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

#### Master-Master Replication

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

### Federation

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

### Denormalizing

> To improve QUERY PERFORMANCE by means of Storage & Redundancy

It's a database design technique that involves **intentionally introducing redundancy** into a database by storing the same data in multiple places. This is done to improve query performance at the cost of increased storage space and potential data update complexities. Here's a simple explanation:

- Imagine you have a database for an e-commerce website, and you want to display product information on the homepage, product listings, and in a user's shopping cart.
- In a normalized database design, you would have a separate table for products and another for product details.
- To display product information on multiple pages, you would need to join these tables in your queries, which can be slow for large datasets.
- Instead, you decide to denormalize by duplicating some product information (e.g., product name, price) directly into the product listings and shopping cart tables.
- Now, you can retrieve this information quickly without **complex joins, improving query performance.**

Example:

- In a normalized database, you might have a "products" table and a "product_details" table.
- In a denormalized design, you duplicate the product name and price directly into the "product_listings" table.
- When a user views a product listing, you can display the product information without the need for a complex join operation.

Denormalization is a **trade-off between query performance and storage efficiency**. It can be useful when you need **to optimize read-heavy operations** but may require careful management to keep redundant data in sync when updates occur.

### SQL Tuning

It's the process of optimizing **SQL queries** to improve their performance and efficiency in interacting with a database. It involves making adjustments to **SQL statements** to ensure they execute as quickly as possible while using the **least amount of resources**. Here's a simple explanation:

- Imagine you have a large database, and you need to retrieve specific data from it using SQL queries.
- If your queries are slow, they can slow down your application and put a strain on the database server.
- SQL tuning involves analyzing and optimizing your SQL queries to make them run faster.
- This can include _rewriting queries, creating indexes, and using appropriate database features_.

Example:

- Let's say you have an e-commerce website, and you want to find all products with a price below $50.
- Initially, your query might be slow because it scans the entire product table.
- After SQL tuning, you rewrite the query to use an index on the "price" column, making the search much faster.

SQL tuning is crucial for maintaining good application performance and ensuring that your database server can handle the workload efficiently. It often requires a combination of **database design**, **query optimization**, and using **appropriate indexing strategies.**

### When to use which RDMS Scaling Techniques

The choice of which technique to use for scaling a relational database depends on various factors, including your specific application's needs and constraints. Here are some guidelines on when to consider each technique based on different scenarios:

1. **Master-Slave Replication**:

   - Use when you have a `read-heavy workload` and a lower write load.
   - Example: If your application's read-to-write ratio is around 100:1, master-slave replication can be effective for offloading read queries to slave databases, reducing the load on the master.

2. **Master-Master Replication**:

   - Consider when you need `high availability and write scalability`.
   - Example: In scenarios where write operations are critical, and you want to ensure redundancy and load balancing, master-master replication can be beneficial.

3. **Federation**:

   - Use when your data can be `logically partitioned` based on certain criteria.
   - Example: In a social media platform, if you want to separate user data by geographic regions (e.g., users in the U.S., Europe, Asia), federation can help distribute data efficiently.

4. **Sharding**:

   - Employ when you have a very large dataset that can be divided into `smaller, manageable pieces`.
   - Example: In e-commerce, if you have millions of products, you can shard your database based on product categories or other criteria to scale horizontally.

5. **Denormalization**:

   - Consider when you need to `optimize read performance` at the cost of increased storage space.
   - Example: In reporting systems, where you need to run complex queries frequently, denormalization can be used to store redundant data that facilitates faster query execution.

6. **SQL Tuning**:
   - Always perform SQL tuning, regardless of the scale, to `optimize query performance`.
   - Example: Continuously monitor your application's SQL queries and optimize them by adding appropriate indexes, rewriting queries, or restructuring them for efficiency.

In practice, it's common to use a combination of these techniques to achieve the desired scalability, performance, and high availability for your application. The choice often depends on the specific characteristics of your data and the workload patterns your application experiences. Regular monitoring and performance testing are essential to fine-tune your database scaling strategy as your application evolves.

### When to use CDN?

Content Delivery Network (CDN) is used to scale a system when your application or website has specific performance and content delivery requirements. CDNs are particularly useful in scenarios where:

**Scenario: Global Website with High Traffic:**

Imagine you have a popular e-commerce website that sells products globally. In this scenario, using a CDN can greatly benefit your system:

1. **Geographical Distribution**: Your website has customers from all over the world. Without a CDN, your web server, which may be located in a single data center, would be responsible for serving content to users across long distances, leading to slow loading times.

2. **High Traffic Peaks**: During special sales events or product launches, your website experiences a massive surge in traffic. This sudden influx of visitors can overload your origin server, causing it to slow down or even crash.

3. **Static and Dynamic Content**: Your website includes both static content (images, stylesheets) and dynamic content (product pages, user-generated content).

How CDN Helps:

- A CDN consists of a `network of geographically distributed` servers (edge servers) located in data centers around the world.
- When you use a CDN, static content like images, stylesheets, and even some cached dynamic content is stored on these edge servers.
- When a user accesses your website, the CDN automatically directs their request to the nearest edge server. This reduces latency and speeds up content delivery.

Benefits:

- **Faster Load Times**: Users receive content from a nearby edge server, resulting in faster load times and a better user experience.
- **Load Balancing**: CDNs distribute traffic across multiple edge servers, reducing the load on your origin server.
- **Scalability**: CDNs can handle spikes in traffic without overloading your origin server.
- **DDoS Mitigation**: CDNs often have built-in security features to protect against Distributed Denial of Service (DDoS) attacks.

In summary, you should consider using a CDN when you need to optimize content delivery, reduce latency for global users, handle traffic spikes, and improve the overall performance and availability of your web application or website.

### Availability Patter

An **availability pattern** refers to a strategy or design approach used to ensure that a system or service remains accessible and operational even in the face of failures or disruptions. Availability patterns are used to enhance the reliability and uptime of applications. Here are two common availability patterns:

1. **Redundancy Pattern**:

   - **Description**: In this pattern, you duplicate critical components or resources, such as servers or databases, so that if one fails, another can take over seamlessly.

   - **Example**: Consider a web application hosted on multiple servers behind a load balancer. If one server becomes unavailable due to a hardware failure, the load balancer can redirect traffic to the remaining healthy servers, ensuring continued service availability. This redundancy pattern is used to achieve high availability.

2. **Failover Pattern**:

   - **Description**: Failover involves automatically switching to a backup system or resource when the primary one fails. This pattern is commonly used for systems that require minimal downtime.

   - **Example**: Think of a database cluster with a primary database server and a secondary (standby) server. If the primary server fails, a failover mechanism automatically promotes the standby server to the primary role. This ensures continuous database operations with minimal interruption.

These availability patterns are essential for building robust and resilient systems. Redundancy ensures that backup resources are available to take over when needed, and failover ensures a smooth transition from a failed resource to a healthy one, minimizing downtime and service interruptions. The choice of pattern depends on the specific availability requirements and constraints of your system.

### Active-Passive vs Active-Active failover

Route 53 active-passive vs active-active failover
The fundamental distinction between the two architectures is when the architecture is operational. During regular operation, we have access to all resources thanks to active-active failover.

In an active-passive failover, backup resources are normally in a standby state and only observe operations during the failover.

#### [Consistency Pattern](https://iq.opengenus.org/consistency-patterns-in-system-design/)
