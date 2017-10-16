const io = require('socket.io')();

io.on('connection', (client) => {
  // in here we can emit events to the client
  client.on('subscribeToTimer', (interval) => {
    console.log('client is subscribing to timer with interval ' + interval);
    setInterval(() => {
      client.emit('timer', new Date()); // emit event named timer with date value to client
    }, interval);
  });
});

const port = 8000;
io.listen(port);
console.log('listening on port ' + port);
