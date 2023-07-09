from typing import Union
from fastapi import Body, FastAPI
from pydantic import BaseModel
from model import Item
from enum import Enum

# create an instance of FastAPI,
# FastAPI is a Python class that provides all the functionality for your API.
app = FastAPI()

'''
When you need to send data from a client (let's say, a browser) to your API, you send it as a request body.

A request body is data sent by the client to your API. A response body is the data your API sends to the client.

Your API almost always has to send a response body. But clients don't necessarily need to send request bodies all the time.
'''

# =>1
# Create a Pydantic model

class Item(BaseModel):
    name: str
    description: Union[str, None] = None # optional
    price: float
    tax: Union[float, None] = None  # optional

@app.post("/new_items/")
async def create_item(item: Item):
    item_dict = item.dict()
    if item.tax:
        price_with_tax = item.price + item.tax
        item_dict.update({"price_with_tax": price_with_tax})
       
    return item_dict

# Use of Body instead of BaseModel

@app.post("/new_items/")
async def create_item(name: str = Body(...), description: str = Body(None), price: float = Body(..., gt=0), tax: float = Body(None)):
    item_dict = {"name": name, "description": description, "price": price, "tax": tax}
    if tax:
        price_with_tax = price + tax
        item_dict.update({"price_with_tax": price_with_tax})
        print(item_dict)
    return item_dict


# ?------------------------------------------------------

# =>2
# Request Body + Path Parameters

@app.put("/new_items/{item_id}")
async def add_new_item(item_id: int, item: Item):
    return {"item_id": item_id, **item.dict()}

# ?------------------------------------------------------

# =>3
# Request Body + Path + Query Parameters

@app.post("/new_items/{new_item_id}")
async def add_another_item(new_item_id: int, item: Item, q: Union[str, None] = None):
    result = {"item_id": new_item_id, **item.dict()}
    if q:
        result.update({"q": q})
    return result

