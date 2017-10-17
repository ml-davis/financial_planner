#pragma once

#include "Communicator.H"

#include <boost/asio.hpp>

class Server
{
  public:
    Server();
    void run();

  private:
    Communicator _communicator;
};
