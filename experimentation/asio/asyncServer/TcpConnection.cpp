#include "TcpConnection.h"

std::string make_daytime_string()
{
  std::time_t now = std::time(0);
  return std::ctime(&now);
}

// the function start() calls boost::asio::sync::write() to serve the data to the client.
void tcp_connection::start()
{
  message_ = make_daytime_string();

  // when initializing the asynchronous operations, and if using boost::bind(), you must specify
  // only the arguments that match the handler's parameter list. In this program, both of the
  // argument placeholders error and bytes_transferred could potentially have been removed
  // since they are not being used in handle_write()
  boost::asio::async_write(socket_,
                           boost::asio::buffer(message_),
                           boost::bind(&tcp_connection::handle_write,
                                       shared_from_this(),
                                       boost::asio::placeholders::error,
                                       boost::asio::placeholders::bytes_transferred));
}

tcp_connection::tcp_connection(boost::asio::io_service& io_service)
  : socket_(io_service)
{
}
