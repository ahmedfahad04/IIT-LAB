from typing import Union
from fastapi import Body, FastAPI
from pydantic import BaseModel
from model import Item
from enum import Enum

# create an instance of FastAPI,
# FastAPI is a Python class that provides all the functionality for your API.
app = FastAPI()


#################### BASIC ####################


# Create path operation decorator with the path /.
# A "path" is also commonly called an "endpoint" or a "route".
@app.get('/')
async def read_root():
    return {'Hello': 'Worlds'}

################ CORS ORIGINS ################

# https://fastapi.tiangolo.com/tutorial/cors/ 

################ RESPONSE MODEL ################
'''
Response model is responsible for determining the data type
of response. 

If we have bool,
    then it accepts True/False, 0/1
If we have str, 
    then it accepts any string, True/False, 1/2/...
If we have int,
    then it accepts 1/2/..., True/False
else
    it returns 'Internal Server Error'
'''
@app.get("/items/{item_id}", response_model=int)
async def read_item(item_id: int):
    if item_id > 5:
        return True 
    else:
        return False 

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

'''

'''
@decorator Info

That @something syntax in Python is called a "decorator".

You put it on top of a function. Like a pretty decorative hat (I guess that's where the term came from).

A "decorator" takes the function below and does something with it.

In our case, this decorator tells FastAPI that the function below corresponds to the path / with an operation get.

It is the "path operation decorator".

'''

'''
1. Import FastAPI.
2. Create an app instance.
3. Write a path operation decorator (like @app.get("/")).
4. Write a path operation function (like def root(): ... above).
5. Run the development server (like uvicorn main:app --reload).
'''
