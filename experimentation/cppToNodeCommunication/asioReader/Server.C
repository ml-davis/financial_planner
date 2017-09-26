#include <iostream>
#include <string>
#include <boost/asio.hpp>

using namespace std;
using tcp = boost::asio::ip::tcp;

namespace asio = boost::asio;

string readMessage(asio::ip::tcp::socket& socket) 
{
  asio::streambuf buffer;
  asio::read_until(socket, buffer, "#");

  string data { asio::buffer_cast<const char*>(buffer.data()) };
  data.erase(--data.end());  // remove the last delimeter
  return data;
}

int main() 
{
  string outgoingMessage { "I am the server" };
  string incomingMessage {};

  asio::io_service io_service;
  tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 13));

  for(;;) {
    tcp::socket socket(io_service);

    cout << "Awaiting message..." << endl;
    acceptor.accept(socket);

    incomingMessage = { readMessage(socket) };
    cout << "Received message: " <<  incomingMessage << endl;;

    cout << "Sending message: " << outgoingMessage << "\n\n";
    asio::write(socket, asio::buffer(outgoingMessage));
  }

  return 0;
}

