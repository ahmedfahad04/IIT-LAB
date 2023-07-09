from typing import Union
from fastapi import FastAPI

app = FastAPI()


# =>1
# Parameter that are not part of the path, they are called "query parameters".
'''
http://127.0.0.1:8000/items/?skip=0&limit=10

...the query parameters are:

skip: with a value of 0
limit: with a value of 10
'''

fake_items_db = [{"item_name": "Foo"}, {"item_name": "Bar"}, {"item_name": "Baz"}]


@app.get("/items/")
async def read_item(skip: int = 0, limit: int = 2):
    return fake_items_db[skip: skip + limit]

# ?------------------------------------------------------

# =>2
# Optional Parameters (quant will be optional and will be None by default. This params start with ?)
# Union[str, None] is equivalent to str | None

@app.get("/prod/")
async def read_item(skip: int = 0, limit: int = 2, quant: Union[str, None] = None):
    return fake_items_db[skip: skip + limit] + [{"quant": quant}]

# ?------------------------------------------------------

# =>3
# Query parameter type conversion (short = 1 or True or on or yes or 1, all will be considered as true)


@app.get("/prod/{prod_id}")
async def read_item(prod_id: str, q: Union[str, None] = None, short: bool = False):
    item = {"item_id": prod_id}
    if q:
        item.update({"q": q})
    if not short:
        item.update(
            {"description": "This is an amazing item that has a long description"}
        )
    return item

# ?------------------------------------------------------

# =>4
# Multiple path and query parameters


@app.get("/users/{user_id}/items/{item_id}")
async def read_user_item(
    user_id: int, item_id: str, q: Union[str, None] = None, short: bool = False
):
    item = {"item_id": item_id, "owner_id": user_id}
    if q:
        item.update({"q": q})
    if not short:
        item.update(
            {"description": "This is an amazing item that has a long description"}
        )
    return item

# ?------------------------------------------------------

# =>5
# Required query parameters (just not declare any default value to make it required)


@app.get("/new_item/{item_id}")
async def read_user_item(item_id: str, needy: str):
    item = {"item_id": item_id, "needy": needy}
    return item

