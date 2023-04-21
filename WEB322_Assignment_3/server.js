/******************************************************************************
                             WEB322 – Assignment 3
Full Name  : Sang Hyon Jeon
Student ID#: 113552194
Email      : shjeon5@myseneca.ca
Section    : NGG
Date       : February 17, 2023

Authenticity Declaration:
I declare that this assignment is my own work in accordance with Seneca
Academic Policy. I have done all the coding by myself and only copied the code
that my professor provided to complete this assignment.

Online (Cyclic) Link: https://ultramarine-petticoat.cyclic.app
******************************************************************************/
const express = require("express");
const multer = require("multer");
const cloudinary = require("cloudinary").v2;
const streamifier = require("streamifier");
const path = require("path");
const blogService = require("./blog-service.js");

// The server must make use of the "express" module
const app = express();

// The server must listen on process.env.PORT || 8080
const HTTP_PORT = process.env.PORT || 8080;

// no { storage: storage } since we are not using disk storage
const upload = multer();

// Set the Cloudinary config to use your "Cloud Name", "API Key" and "API Secret" values
cloudinary.config({
  cloud_name: "dpju16bxg",
  api_key: "528451683481667",
  api_secret: "gU9teO1Y7g3BGj-yisQdph-xEag",
  secure: true,
});

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

// This route "/posts" gets posts within posts.json by category, minDate, or just all the posts
app.get("/posts", (req, res) => {
  let category = req.query.category;
  let minDate = req.query.minDate;
  let returnedPromise = null;

  if (category) {
    returnedPromise = blogService.getPostsByCategory(category);
  } else if (minDate) {
    returnedPromise = blogService.getPostsByMinDate(minDate);
  } else {
    returnedPromise = blogService.getAllPosts();
  }

  returnedPromise
    .then((data) => {
      res.json(data);
    })
    .catch((err) => {
      res.json({ message: err });
    });
});

// This route will return a JSON formatted string containing a single post whose id matches the value
app.get("/post/:id", (req, res) => {
  let postId = req.params.id;

  blogService
    .getPostById(postId)
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

// This route simply sends the file "/views/addPost.html"
app.get("/posts/add", (req, res) => {
  res.sendFile(path.join(__dirname, "views", "addPost.html"));
});

app.post("/posts/add", upload.single("featureImage"), (req, res) => {
  let streamUpload = (req) => {
    return new Promise((resolve, reject) => {
      let stream = cloudinary.uploader.upload_stream((error, result) => {
        if (result) {
          resolve(result);
        } else {
          reject(error);
        }
      });

      streamifier.createReadStream(req.file.buffer).pipe(stream);
    });
  };

  async function upload(req) {
    let result = await streamUpload(req);
    console.log(result);
    return result;
  }

  upload(req).then((uploaded) => {
    req.body.featureImage = uploaded.url;

    // Process the req.body and add it as a new Blog Post before redirecting to /posts
    blogService.addPost(req.body).then((postData) => {
      res.redirect("/posts");
    });
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
