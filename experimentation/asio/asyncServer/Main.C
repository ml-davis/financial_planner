#include "TcpServer.H"

int main()
{
  try
  {
    // We need to create a server object to accept incoming client connections.
    // The io_service object provides i/o services, such as sockets, that the server object will use.
    boost::asio::io_service io_service;
    tcp_server server(io_service);

    // run the io_service object so that it will performa asynchronous operations on your behalf
    io_service.run();
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }
}
