import openSocket from 'socket.io-client';
const socket = openSocket('http://192.168.0.109:8000');

function makeRequest(cb, request) {
  socket.on('response', display => cb(null, display));
  socket.emit('makeRequest', request);
}

export { makeRequest }
