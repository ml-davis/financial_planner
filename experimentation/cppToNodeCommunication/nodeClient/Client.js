const net = require('net');

const HOST = '127.0.0.1';
const PORT = 13;

const message = 'I am the client';

const client = new net.Socket();
client.connect(PORT, HOST, function() {
  console.log('Connected to: ' + HOST + ':' + PORT + '\n');
  console.log('Sending message: ' + message);
  client.write(message + '#');
});

client.on('data', function(data) {
  console.log('Got response: ' + data + '\n');
  client.destroy();
});

client.on('close', function() {
  console.log('Connection closed');
});
