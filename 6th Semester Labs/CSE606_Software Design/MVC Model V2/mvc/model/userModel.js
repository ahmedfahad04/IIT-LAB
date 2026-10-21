// const User = require('../model/userModel');
const express = require('express');
const router = express.Router();
const mongoose = require('mongoose');
const Schema = mongoose.Schema;

const userSchema = new Schema({
    name: {type: String},
    password: {type: String},
    email: {type: String},
    phone: {type: String}
}, {timestamps: true});


const User = mongoose.model("User", userSchema);

// interaction with model 
const registration = (req, res) => {
    console.log(req.body)

    const newUser = new User({
        name: req.body.name,
        password: req.body.password,
        email: req.body.email,
        phone: req.body.phone    
    })

    newUser.save()
    .then((user) => {
        res.json({
            message: 'User Created Successfully',
        })
    })
    .catch((err) => {
        res.status(400).json({
            error: err
        })
    });
}

const userData = (req, res) => {

    User.find()
      .then((response) => {
        res.json(response)
      })
      .catch((error) => {
        res.json({
          message: 'An error occurred! Post showcasing failed!',
        });
      });

}

// process the request using routes
router.post('/reg', registration);
router.get('/all', userData);

// export router 
module.exports = router;