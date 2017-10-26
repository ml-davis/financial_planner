const io = require('socket.io')();
const net = require('net');

const HOST = 'localhost';
const CPP_PORT = 2020;
const JS_PORT = 8000;


io.on('connection', (jsClient) => {
  jsClient.on('makeRequest', (request) => {

    const cppClient = new net.Socket();

    cppClient.connect(CPP_PORT, HOST, () => {
      console.log('Connected to: ' + HOST + ':' + CPP_PORT + '\n');
      console.log('Sending request: ' + request);
      cppClient.write(request + '#');
    });

    cppClient.on('data', (data) => {
      console.log('Got response: \n\n' + data + '\n');
      jsClient.emit('response', String.fromCharCode.apply(null, new Uint16Array(data)));
      cppClient.destroy();
    });

    cppClient.on('close', () => {
      console.log('Connection closed');
    });

  });
});

io.listen(JS_PORT);
console.log('listening on port ' + JS_PORT);
