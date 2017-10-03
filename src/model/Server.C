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
{}

void Server::run() 
{
  string request {};

  asio::io_service io_service;
  tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 2020));

  for(;;) {
    tcp::socket socket(io_service);

    cout << "Awaiting message..." << endl;
    acceptor.accept(socket);

    request = { readMessage(socket) };
    cout << "Received message: " <<  request << "\n\n";;

    string response { _communicator.fetchData(request) };
    cout << "Sending message: \n\n" << response << "\n\n";
    asio::write(socket, asio::buffer(response));
  }
}
