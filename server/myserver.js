const express=require("express");
const net = require('net');
const port = 8080;
const server = new net.Server();
server.listen(port, function() {
    console.log(`Server listening for connection requests on socket localhost:${port}`);
});
server.on('connection', function(socket) {
    console.log('A new connection has been established.');
      socket.on('data', function(chunk) {
        //console.log(`Data received from client: ${chunk.toString()}`);
        parseBuffer(chunk);
       // console.log(chunk.toJSON());
    });
    socket.on('close', function() {
        console.log('Closing connection with the client');
    });
    socket.on('error', function(err) {
        console.log(`Error: ${err}`);
    });

          
    function parseBuffer(buffer) {
        let message = {}
        message.type =Buffer.from(buffer).readInt8(0)
        if (message.type == 1) {
            message.status = Buffer.from(buffer).readInt8(2)
        } else {
            message.distance = Buffer.from(buffer).readFloatLE(2);
            message.angle = Buffer.from(buffer).readFloatLE(6);
            message.speed = Buffer.from(buffer).readFloatLE(10);
        
        }
        console.log(message);
    }

});