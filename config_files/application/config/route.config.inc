/*
 * All application routes should be defined here
 */

{
  "GET /": {
    "platform": "app",
    "controller": "index",
    "action": "index"
  },
  "GET /:id": {
    "platform": "app",
    "controller": "index",
    "action": "view"
  }
}