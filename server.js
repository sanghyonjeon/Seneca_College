/******************************************************************************
                             WEB322 – Assignment 2
Full Name  : Sang Hyon Jeon
Student ID#: 1123552194
Email      : shjeon5@myseneca.ca
Section    : NBB
Date       : February 3, 2023

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
******************************************************************************/
var path = require("path");
// The server must make use of the "express" module
var express = require("express");
var app = express();

// The server must listen on process.env.PORT || 8080
var HTTP_PORT = process.env.PORT || 8080;

// The server must output: "Express http server listening on port" to the
// console, where port is the port the server is currently listening on
app.listen(HTTP_PORT, () => {
  console.log(`Express http server listening on ${HTTP_PORT}`);
});

// For your server to correctly return the "/css/main.css" file, the "static"
// middleware must be used
app.use(express.static("public"));

// The route "/" must redirect the user to the "/about" route
app.get("/", (req, res) => {
  res.redirect("/about");
});

//The route "/about" must return the about.html file from the views folder
app.get("/about", (req, res) => {
  res.sendFile(path.join(__dirname, "/views/about.html"));
});
