const fs = require("fs");

var posts = [];
var categories = [];

function initialize() {
  return new Promise((resolve, reject) => {
    fs.readFile("./data/posts.json", "utf8", (err, data) => {
      if (err) {
        reject("unable to read file: " + __filename);
      } else {
        posts = JSON.parse(data);

        fs.readFile("./data/categories.json", "utf8", (err, data) => {
          if (err) {
            reject("unable to read file: " + __filename);
          } else {
            categories = JSON.parse(data);
            resolve();
          }
        });
      }
    });
  });
}

function getAllPosts() {
  return new Promise((resolve, reject) => {
    if (posts.length == 0) {
      reject("no results returned");
    } else {
      resolve(posts);
    }
  });
}

function getPublishedPosts() {
  return new Promise((resolve, reject) => {
    let publishedPosts = posts.filter((post) => post.published);

    if (publishedPosts.length == 0) {
      reject("no results returned");
    } else {
      resolve(publishedPosts);
    }
  });
}

function getCategories() {
  return new Promise((resolve, reject) => {
    if (categories.length === 0) {
      reject("no results returned");
    } else {
      resolve(categories);
    }
  });
}

function addPost(postData) {
  return new Promise((resolve, reject) => {
    if (postData.published == undefined) {
      postData.published = false;
    } else {
      postData.published = true;
    }

    // Add the property "postDate" to the postData object
    let currentDate = new Date();
    let formattedDate = `${currentDate.getFullYear()}-${
      currentDate.getMonth() + 1
    }-${currentDate.getDate()}`;
    postData.postDate = formattedDate;

    postData.id = posts.length + 1;
    posts.push(postData);
    resolve(postData);
  });
}

function getPostsByCategory(category) {
  return new Promise((resolve, reject) => {
    let postsByCategory = posts.filter((post) => post.category == category);

    if (postsByCategory.length == 0) {
      reject("no results returned");
    } else {
      resolve(postsByCategory);
    }
  });
}

function getPostsByMinDate(minDateStr) {
  return new Promise((resolve, reject) => {
    let postsByMinDate = posts.filter(
      (post) => new Date(post.postDate) >= new Date(minDateStr)
    );

    if (postsByMinDate.length == 0) {
      reject("no results returned");
    } else {
      resolve(postsByMinDate);
    }
  });
}

function getPostById(id) {
  return new Promise((resolve, reject) => {
    let postById = posts.find((post) => post.id == id);

    if (!postById) {
      reject("no result returned");
    } else {
      resolve(postById);
    }
  });
}

function getPublishedPostsByCategory(category) {
  return new Promise((resolve, reject) => {
    let publishedPosts = posts.filter(
      (post) => post.published && post.category == category
    );

    if (publishedPosts.length == 0) {
      reject("no results returned");
    } else {
      resolve(publishedPosts);
    }
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
  getPublishedPostsByCategory,
};
