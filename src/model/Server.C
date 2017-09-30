#include "Server.H"

using namespace std;
using tcp = boost::asio::ip::tcp;

namespace asio = boost::asio;

string readMessage(tcp::socket& socket) 
{
  asio::streambuf buffer;
  asio::read_until(socket, buffer, "#");

  string data { asio::buffer_cast<const char*>(buffer.data()) };
  data.erase(--data.end());  // remove the last delimeter
  return data;
}

Server::Server()
  : _communicator{ Communicator() }
{
  _communicator.changeDate("2017-Aug-01");
}

void Server::run() 
{
  string outgoingMessage { _communicator.getRemaining() };
  string incomingMessage {};

  asio::io_service io_service;
  tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 2020));

  for(;;) {
    tcp::socket socket(io_service);

    cout << "Awaiting message..." << endl;
    acceptor.accept(socket);

    incomingMessage = { readMessage(socket) };
    cout << "Received message: " <<  incomingMessage << "\n\n";;

    cout << "Sending message: \n\n" << outgoingMessage << "\n\n";
    asio::write(socket, asio::buffer(outgoingMessage));
  }
}
