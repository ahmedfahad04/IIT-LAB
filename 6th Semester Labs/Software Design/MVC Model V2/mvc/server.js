const express = require('express');
const mongoose = require('mongoose');
const morgan = require('morgan');
const bodyParser = require('body-parser');
const cors = require('cors');
const userRoutes = require('./model/userModel'); 

// connect to mongo
mongoose.connect('mongodb://127.0.0.1:27017/IIT', { useNewUrlParser: true, useUnifiedTopology: true });
const db = mongoose.connection;

db.on('error', (err) => {console.log(err);})
db.once('open', () => {console.log('DB connection established')});

// init app
const app = express();
app.use(morgan('dev'));
app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());

// listen on port 5050
const PORT = 5000;
app.listen(PORT, () => {console.log(`Listening on port ${PORT}`)});

// middleware 
app.use(cors());

// routers
app.use('/api/users', userRoutes)
