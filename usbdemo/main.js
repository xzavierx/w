const http = require('http');
const hostname = '0.0.0.0';
const port = 3000;

var connect = require('connect'),
    directory = './console';

connect()
    .use(connect.static(directory))
    .listen(80);