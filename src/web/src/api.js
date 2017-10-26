import openSocket from 'socket.io-client';
const socket = openSocket('http://192.168.0.109:8000');

function makeRequest(request, cb) {
  socket.removeAllListeners();
  socket.emit('makeRequest', request);
  socket.on('response', display => cb(display));
}

export { makeRequest }
