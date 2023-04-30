from fastapi import FastAPI
from FastAPI_Tuts.model import Item
import db_model 


app = FastAPI()

@app.on_event('startup')
async def connect_with_db():
    await db_model.connect_db()


@app.post('/items/', response_model=Item)
async def create_item(item: Item):
    await db_model.insert(item)
    return item

@app.delete('/items/{id}')
async def delete_item(id: int):
    await db_model.delete(id)
    return {"message": "item deleted"}
    
# here response model is of no use
@app.put('/items/')
async def update_item(item: Item):
    await db_model.update(item)
    return {"message": "item updated"}












# path parameter
# @app.get('/items/{item_id}')

# query parameter
# @app.get('/items/{item_id}/?skip=08')

# request body
# @app.post('/items/', response_model=Item)