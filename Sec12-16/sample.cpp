#include "Simple_window.h"
#include "Graph.h"

// g++-9 -std=c++14 -I/usr/local/Cellar/fltk/1.3.5/include -L/usr/local/Cellar/fltk/1.3.5/lib -lfltk -lfltk_images -lpthread -framework Cocoa -o ./a.out Graph.cpp GUI.cpp Simple_window.cpp Window.cpp sample.cpp

int main()
{
  using namespace Graph_lib;
  Point tl{100, 100};
  Simple_window win{tl, 600, 400, "Canvas"};
  Polygon poly;
  poly.add(Point{300, 200});
  poly.add(Point{350, 100});
  poly.add(Point{400, 200});
  poly.set_color(Color::red);
  win.attach(poly);
  win.wait_for_button();
}