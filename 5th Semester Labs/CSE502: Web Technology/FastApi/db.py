from databases import Database
import sqlalchemy

from model import Item

# establish connection with mysql
database = Database("mysql+aiomysql://root:12345678@localhost:3306/practice")

async def connect_db():         # async => baki part running thakbe, 
    await database.connect()    # db connection complete hole, next line theke run korbe
  
    
async def insert(item: Item):
    query = "insert into items (id, name, price) values(:id, :name, :price)"
    values = {"id": item.id, "name": item.name, "price": item.price}
    await database.execute(query=query, values=values)
    
    
async def delete(id: int):
    query = "delete from items where id=:id"
    values = {"id": id}
    await database.execute(query=query, values=values)

    
async def update(item: Item):
    query = "UPDATE items SET name=:name, price=:price WHERE id=:id"
    values = {"id": item.id, "name": item.name, "price": item.price}
    await database.execute(query=query, values=values)


    
    
    
    
    
    
    
    
    
    
    