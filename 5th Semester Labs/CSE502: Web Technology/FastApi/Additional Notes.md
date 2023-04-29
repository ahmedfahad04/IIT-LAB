# Concurrency and async / await (Async/Await)[https://fastapi.tiangolo.com/async/#in-a-hurry]

You can only use **await** inside of functions created with **async** def.

**What is Async in FASTAPI?**

Async in FASTAPI refers to the ability to write asynchronous code using the async/await syntax in Python. Async allows for non-blocking I/O operations, which means that the code can continue to execute while waiting for a response from an external resource, such as a database or API.

**What is Await?**

Await is a keyword used in Python to indicate that a function should wait for a coroutine to complete before continuing execution. When used in conjunction with async, await allows for the execution of other code while waiting for a coroutine to complete.

**Why & When is it used?**

Async and await are used in FASTAPI to improve the performance of web applications by allowing for non-blocking I/O operations. This means that the application can handle multiple requests simultaneously, without blocking the execution of other code. Async is particularly useful when working with external resources that may take a long time to respond, such as databases or APIs.

**Benefits of it:**

The benefits of using async and await in FASTAPI include improved performance, scalability, and responsiveness of web applications. By allowing for non-blocking I/O operations, async enables web applications to handle multiple requests simultaneously, without blocking the execution of other code. This can result in faster response times and improved user experience.

**FASTAPI Examples:**

Here is an example of using async and await in FASTAPI to perform a database query:

```python
from fastapi import FastAPI
from databases import Database

app = FastAPI()
database = Database("sqlite:///example.db")

@app.get("/users")
async def get_users():
    query = "SELECT * FROM users"
    results = await database.fetch_all(query)
    return {"users": results}
```

In this example, The key here is the await. It tells Python that it has to wait. The get_users function uses async and await to perform a database query asynchronously, without blocking the execution of other code. The results of the query are then returned as a JSON response to the client.


# Coroutines

**What is a Coroutine?**

A coroutine is a specialized function that can pause execution and return control to the caller, while retaining its state. This allows for non-blocking I/O operations and can improve the performance of applications that rely heavily on I/O operations. Coroutines are commonly used in Python with the async/await syntax to write asynchronous code.

**Example:**

Here is an example of a coroutine in Python:

```python
async def my_coroutine():
    print("Coroutine started")
    await asyncio.sleep(1)
    print("Coroutine resumed")
```

In this example, the my_coroutine function is defined as a coroutine using the async keyword. The function prints a message, then uses the await keyword to pause execution for one second using the asyncio.sleep function. After one second, the function resumes execution and prints another message.

**FASTAPI Example:**

Here is an example of using a coroutine in FASTAPI to perform an asynchronous task:

```python
from fastapi import FastAPI
import asyncio

app = FastAPI()

async def my_task():
    await asyncio.sleep(1)
    print("Task completed")

@app.get("/async")
async def async_endpoint():
    asyncio.create_task(my_task())
    return {"message": "Task started"}
```

In this example, the async_endpoint function uses the create_task function from the asyncio module to create a new task that executes the my_task coroutine asynchronously. The function returns a JSON response to the client indicating that the task has started. The my_task coroutine uses the await keyword to pause execution for one second using the asyncio.sleep function, then prints a message indicating that the task has completed.


# Concurrency vs Parallelism 
Concurrency and Parallelism are both techniques used to improve the performance and responsiveness of applications, but they differ in how they execute tasks. Concurrency allows for overlapping execution of tasks, while parallelism allows for simultaneous execution of tasks. The choice between concurrency and parallelism depends on the nature of the tasks being performed and the resources available for execution.

<i>A real life example:</i>

Imagine you are a chef in a busy restaurant. You have to prepare many dishes at the same time to serve all the customers. You have a stove with four burners, and you can only cook one dish on each burner at a time.

Concurrency is like having one chef and four different dishes cooking on each burner at different times. For example, you might start cooking pasta on one burner, then switch to cooking vegetables on another burner while the pasta is boiling. You keep switching between the burners to make sure all the dishes are cooking at the same time.

Parallelism, on the other hand, is like having four chefs, each with their own stove and ingredients, cooking the same dishes at the same time. Each chef can cook a different dish simultaneously, and all the dishes will be ready at the same time.

Concurrency allows the chef to handle multiple tasks simultaneously, while parallelism allows multiple chefs to handle the same tasks simultaneously. Both techniques can improve the efficiency and speed of cooking, just as they can improve the performance of computer programs.


# Is Async/Await Concurrent or Parallel?

Async/await is a **concurrent programming model** that allows for non-blocking I/O operations. It enables a **single thread** to handle multiple tasks simultaneously by switching between them when they are blocked, rather than waiting for them to complete.

Async/await is not inherently parallel, as it does not involve multiple threads or processors executing tasks simultaneously. However, it can be used in conjunction with parallel programming models, such as multiprocessing or multithreading, to achieve both concurrency and parallelism. Overall, async/await is a powerful tool for improving the performance and responsiveness of applications that rely heavily on I/O operations.

