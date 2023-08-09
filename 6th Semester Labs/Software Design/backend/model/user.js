const mongoose = require('mongoose');
const Schema = mongoose.Schema;

const userSchema = new Schema({
    name: {type: String},
    password: {type: String},
    email: {type: String},
    phone: {type: String}
}, {timestamps: true});

const user = mongoose.model("User", userSchema);
module.exports = user;

