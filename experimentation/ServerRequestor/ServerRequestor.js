const net = require('net');

const HOST = 'localhost';
const PORT = 2020;

const client = new net.Socket();

const message = 'FETCH EXPENSE_TYPES';

client.connect(PORT, HOST, function() {
  console.log('Connected to: ' + HOST + ':' + PORT + '\n');
  console.log('Sending message: ' + message);
  client.write(message + '#');
});

client.on('data', function(data) {
  console.log('Got response: \n\n' + data + '\n');
  client.destroy();
});

client.on('close', function() {
  console.log('Connection closed');
});

