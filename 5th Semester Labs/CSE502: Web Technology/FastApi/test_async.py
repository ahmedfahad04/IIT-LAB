from fastapi import FastAPI
import asyncio
from time import sleep

app = FastAPI()

# normal function without async
def my_task():
    sleep(5)
    print("Task completed")

@app.get("/normal")
def async_endpoint():
    my_task()
    return {"message": "Task started without async"}


# same function with async
async def my_task2():
    await asyncio.sleep(2)
    print("Task completed")

@app.get("/async")
async def async_endpoint2():
    asyncio.create_task(my_task2())
    return {"message": "Task started"}