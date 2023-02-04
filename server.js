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

Online (Cyclic) Link: 
******************************************************************************/
var blogService = require("./blog-service.js");
var path = require("path");
// The server must make use of the "express" module
var express = require("express");
var app = express();

// The server must listen on process.env.PORT || 8080
var HTTP_PORT = process.env.PORT || 8080;

// For your server to correctly return the "/css/main.css" file, the "static"
// middleware must be used
app.use(express.static("public"));

// The route "/" must redirect the user to the "/about" route
app.get("/", (req, res) => {
  res.redirect("/about");
});

// The route "/about" must return the about.html file from the views folder
app.get("/about", (req, res) => {
  res.sendFile(path.join(__dirname, "views", "about.html"));
});

// The route "/blog" gets all posts who have published property set to true within posts.json
app.get("/blog", (req, res) => {
  blogService
    .getPublishedPosts()
    .then((data) => {
      res.json(data);
    })
    .catch((err) => {
      res.json({ message: err });
    });
});

// This route "/posts" gets all posts within posts.json
app.get("/posts", (req, res) => {
  blogService
    .getAllPosts()
    .then((data) => {
      res.json(data);
    })
    .catch((err) => {
      res.json({ message: err });
    });
});

// This route "/categories" gets all categories within the categories.json
app.get("/categories", (req, res) => {
  blogService
    .getCategories()
    .then((data) => {
      res.json(data);
    })
    .catch((err) => {
      res.json({ message: err });
    });
});

// Any other routes will return a custom message with an HTTP status code
app.use((req, res) => {
  res.status(404).send("Page Not Found");
});

blogService
  .initialize()
  .then(() => {
    // The server must output: "Express http server listening on port" to the
    // console, where port is the port the server is currently listening on
    app.listen(HTTP_PORT, () => {
      console.log("Express http server listening on " + HTTP_PORT);
    });
  })
  .catch((err) => {
    console.error(err);
  });
