const User = require('../model/user');
const express = require('express');
const router = express.Router();

// interaction with model 
const registration = (req, res) => {
    const { name, password, email, phone } = req.body;
    console.log(req.body)

    const newUser = new User({
        name: name,
        password: password,
        email: email,
        phone: phone    
    })

    newUser.save()
    .then((user) => {
        res.json({
            message: 'User Created Successfully'
        })
    })
    .catch((err) => {
        res.status(400).json({
            error: err
        })
    });
}

// process the request using routes
router.post('/register', registration)

// export router 
module.exports = router;