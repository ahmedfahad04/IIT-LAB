from fastapi import FastAPI
from enum import Enum

# create an instance of FastAPI,
# FastAPI is a Python class that provides all the functionality for your API.
app = FastAPI()


# => 1
# path operation with PATH PARAMETERS (item_id)


@app.get("/items/{item_id}")
async def read_item(item_id):
    return {
        "item_id": item_id
    }

# ?------------------------------------------------------

# => 2
# path operation with PATH PARAMETERS (item_id, q) with type


@app.get("/items/{item_id}/{q}")
async def read_item(item_id: int, q: str):
    return {
        "item_id": item_id, "q": q
    }

# ?------------------------------------------------------

# => 3
# path operations are evaluated in order, you need to make sure that
# the path for /users/me is declared before the one for /users/{user_id}:


@app.get("/users/me")
async def read_user_me():
    return {"user_id": "the current user"}


@app.get("/users/{user_id}")
async def read_user(user_id: str):
    return {"user_id": user_id}
# !Otherwise, the path for /users/{user_id} would match also for
# !/users/me, "thinking" that it's receiving a parameter user_id with a value of "me".

# ?------------------------------------------------------

# =>4
# We cannot redefine a path operation


@app.get("/users")
async def read_users():
    return ["Rick", "Morty"]

# it won't execute


@app.get("/users")
async def read_users2():
    return ["Bean", "Elfo"]

# ?------------------------------------------------------

# =>5
# Predefined Path Parameters Value using ENUM


class ModelName(str, Enum):
    alexnet = "alexnet"
    resnet = "resnet"
    lenet = "lenet"


@app.get("/models/{model_name}")
async def get_model(model_name: ModelName):
    if model_name is ModelName.alexnet:
        return {"model_name": model_name, "message": "Deep Learning FTW!"}

    if model_name.value == "lenet":
        return {"model_name": model_name, "message": "LeCNN all the images"}

    return {"model_name": model_name, "message": "Have some residuals"}

# ?------------------------------------------------------

# =>6
# Path Pramater Containing Paths (using Path Converter)


# ! becareful, you can't give space between the : here.
@app.get("/files/{file_path:path}")
async def read_file(file_path: str):
    return {"file_path": file_path}
