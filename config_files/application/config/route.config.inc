/*
 * Define Custom Route.
 */


{
  "GET /": {
    "platform": "app",
    "controller": "index",
    "action": "index"
  },
  "GET /list/": {
    "platform": "app",
    "controller": "index",
    "action": "list"
  },
  "GET /edit/:id": {
    "platform": "app",
    "controller": "index",
    "action": "edit"
  },
  "POST /edit/:id": {
    "platform": "app",
    "controller": "index",
    "action": "edit"
  },
  "GET /delete/:id": {
    "platform": "app",
    "controller": "index",
    "action": "delete"
  },
  "GET /add/": {
    "platform": "app",
    "controller": "index",
    "action": "add"
  },
  "POST /add/": {
    "platform": "app",
    "controller": "index",
    "action": "add"
  }
}