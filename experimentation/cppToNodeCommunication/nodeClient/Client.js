const net = require('net');

const HOST = '127.0.0.1';
const PORT = 13;

const client = new net.Socket();
client.connect(PORT, HOST, function() {
  console.log('Connected to: ' + HOST + ':' + PORT);
  client.write('I am Chuck Norris');
});

client.on('data', function(data) {
  console.log('Data: ' + data);
  client.destroy();
});

client.on('close', function() {
  console.log('Connection closed');
});
