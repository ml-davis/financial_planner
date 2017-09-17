#include "HelloWorld.H"

#include <iostream>

HelloWorld::HelloWorld()
  : m_button("Hello World")
{
  set_border_width(10);

  // When button receives click signal,
  // it will call the on_button_clicked() method defined below
  m_button.signal_clicked().connect(sigc::mem_fun(*this, &HelloWorld::on_button_clicked));

  // add button in the window (container)
  add(m_button);

  // display button
  m_button.show();
}

HelloWorld::~HelloWorld()
{}

void HelloWorld::on_button_clicked()
{
  std::cout << "Hello World!" << std::endl;
}
