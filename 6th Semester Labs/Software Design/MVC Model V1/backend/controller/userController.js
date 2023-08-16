const User = require('../model/userModel');
const express = require('express');
const router = express.Router();

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