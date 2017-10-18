#pragma once

#include <guiAccessLayer/Communicator.h>

#include <boost/asio.hpp>

class Server
{
  public:
    Server();
    void run();

  private:
    Communicator _communicator;
};
