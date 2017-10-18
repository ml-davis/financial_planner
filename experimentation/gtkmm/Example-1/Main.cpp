#include "HelloWorld.h"

#include <gtkmm/application.h>

int main(int argc, char* argv[])
{
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

  HelloWorld helloWorld;

  // shows the window and returns it when closed
  return app->run(helloWorld);
}
