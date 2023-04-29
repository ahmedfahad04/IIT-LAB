from fastapi import FastAPI
from model import Item

app = FastAPI()

## GET request

@app.get('/')
def read_root():
    return {'Hello': 'World'}

    
# if you have same link with different type of data
# then the first one will be counted, later one 
# will be ignored

# @app.get("/items/{item_id}/{q}")
# async def read_item(item_id: int, q: int):
#     return {
#         "item_id": item_id, "q": q
#     }

# confusing method age use korbo

@app.post('/bool', response_model=bool)
async def read_bopl():
    return True

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
    
## POST request

@app.post('/items/', response_model=Item)
async def create_item(item: Item):
    return item

@app.put('/items/', response_model=Item)
async def update_item(item: Item):
    return item

@app.delete('/items/', response_model=Item)
async def delete_item(item: Item):
    return item


