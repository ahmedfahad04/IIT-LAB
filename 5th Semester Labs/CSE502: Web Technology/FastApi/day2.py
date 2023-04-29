from fastapi import FastAPI
from model import Item
import db 

app = FastAPI()

@app.on_event('startup')
async def connect_with_db():
    await db.connect_db()


@app.post('/items/', response_model=Item)
async def create_item(item: Item):
    await db.insert(item)
    return item

@app.delete('/items/{id}')
async def delete_item(id: int):
    await db.delete(id)
    return {"message": "item deleted"}
    
@app.put('/items/', response_model=Item)
async def update_item(item: Item):
    await db.update(item)
    return {"message": "item updated"}











# path parameter
# @app.get('/items/{item_id}')

# query parameter
# @app.get('/items/{item_id}/?skip=08')

# request body
# @app.post('/items/', response_model=Item)