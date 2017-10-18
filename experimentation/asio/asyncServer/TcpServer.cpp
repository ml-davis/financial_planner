#include "TcpConnection.h"
#include "TcpServer.h"

using boost::asio::ip::tcp;

// the constructor initializes an acceptor to listen on TCP port 13
tcp_server::tcp_server(boost::asio::io_service& io_service)
  : acceptor_(io_service, tcp::endpoint(tcp::v4(), 13))
{
  start_accept();
}

// the function start_accept() creates a socket and initializes an asynchronous accept
// operation to wait for a new connection
void tcp_server::start_accept()
{
  tcp_connection::pointer new_connection = tcp_connection::create(acceptor_.get_io_service());
  acceptor_.async_accept(new_connection->socket(),
                         boost::bind(&tcp_server::handle_accept,
                                     this,
                                     new_connection,
                                     boost::asio::placeholders::error));
  std::cout << "Awaiting message..." << std::endl;
}

// the function handle_accept() is called when the asynchronous accept orientation initialized by
// start_accept() finishes. It services the client request, and then calls start_accept() to initialize
// the next accept operation
void tcp_server::handle_accept(tcp_connection::pointer new_connection,
                               const boost::system::error_code& error)
{
  if (!error)
  {
    new_connection->start();
  }

  start_accept();
}
