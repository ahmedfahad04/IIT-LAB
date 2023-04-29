from fastapi import FastAPI
from model import Item

# create an instance of FastAPI,
# !FastAPI is a Python class that provides all the functionality for your API.
app = FastAPI()

# GET request

# Create path operation decorator with the path /.
# !A "path" is also commonly called an "endpoint" or a "route".
@app.get('/')
async def read_root():
    return {'Hello': 'Worlds'}


@app.get("/items/{item_id}/{q}")
async def read_item(item_id: int, q: str):
    return {
        "item_id": item_id, "q": q
    }


@app.get("/items/{item_id}", response_model=bool)
async def read_item(item_id: int):
    if item_id > 5:
        return False
    else:
        return True

# POST request


@app.post('/bool', response_model=bool)
async def read_bool():
    return True


@app.post('/items/', response_model=Item)
async def create_item(item: Item):
    return item


@app.put('/items/', response_model=Item)
async def update_item(item: Item):
    return item


@app.delete('/items/', response_model=Item)
async def delete_item(item: Item):
    return item


######### NOTES #########

'''
if you have same link with different type of data
then the first one will be counted, later one
will be ignored

@app.get("/items/{item_id}/{q}")
async def read_item(item_id: int, q: int):
    return {
        "item_id": item_id, "q": q
    }

confusing method age use korbo
'''

'''
@decorator Info

That @something syntax in Python is called a "decorator".

You put it on top of a function. Like a pretty decorative hat (I guess that's where the term came from).

A "decorator" takes the function below and does something with it.

In our case, this decorator tells FastAPI that the function below corresponds to the path / with an operation get.

It is the "path operation decorator".
'''
