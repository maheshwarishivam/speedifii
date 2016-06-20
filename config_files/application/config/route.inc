/*
 * Define Custom Route.
 */


{
  "POST /model/index/view/:variable1/:variable2": {
    "platform": "app",
    "controller": "index",
    "action": "index"
  },
  "GET /model/index/view/:variable1/": {
    "platform": "app",
    "controller": "index",
    "action": "view"
  },
  "POST /platform/controller/action/:variable5/:variable6": {
    "platform": "app",
    "controller": "indexv",
    "action": "index"
  },
  "POST /platform/controller/action/:variable7/:variable8": {
    "platform": "app",
    "controller": "index",
    "action": "index"
  }
}