const fs = require("fs");

var posts = [];
var categories = [];

function initialize() {
  return new Promise(function (resolve, reject) {
    fs.readFile("./data/posts.json", "utf8", (err, data) => {
      if (err) return reject("unable to read file: " + __filename);
      posts = JSON.parse(data);

      fs.readFile("./data/categories.json", "utf8", (err, data) => {
        if (err) return reject("unable to read file: " + __filename);
        categories = JSON.parse(data);

        resolve();
      });
    });
  });
}

function getAllPosts() {
  return new Promise(function (resolve, reject) {
    if (posts.length === 0) return reject("no results returned");
    resolve(posts);
  });
}

function getJPublishedPosts() {
  return new Promise(function (resolve, reject) {
    var publishedPosts = posts.filter((post) => post.published === true);
    if (publishedPosts.length === 0) return reject("no results returned");
    resolve(publishedPosts);
  });
}

function getCategories() {
  return new Promise((resolve, reject) => {
    if (categories.length === 0) return reject("no results returned");
    resolve(categories);
  });
}
