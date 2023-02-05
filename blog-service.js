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

function getPublishedPosts() {
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

function addPost(postData) {
  return new Promise((resolve, reject) => {
    if (postData.published === undefined) {
      postData.published = false;
    } else {
      postData.published = true;
    }
    postData.id = posts.length + 1;
    posts.push(postData);
    resolve(postData);
  });
}

function getPostsByCategory(category) {
  return new Promise((resolve, reject) => {
    var postsByCategory = posts.filter((post) => post.category === category);
    if (postsByCategory.length === 0) return reject("no results returned");
    resolve(postsByCategory);
  });
}

function getPostsByMinDate(minDateStr) {
  return new Promise((resolve, reject) => {
    var postsByMinDate = posts.filter(
      (post) => new Date(post.postDate) >= new Date(minDateStr)
    );
    if (postsByMinDate.length === 0) return reject("no results returned");
    resolve(postsByMinDate);
  });
}

function getPostById(id) {
  return new Promise((resolve, reject) => {
    var post = posts.find((post) => post.id === id);
    if (!post) return reject("no result returned");
    resolve(post);
  });
}

module.exports = {
  initialize,
  getAllPosts,
  getPublishedPosts,
  getCategories,
  addPost,
  getPostsByCategory,
  getPostsByMinDate,
  getPostById,
};
