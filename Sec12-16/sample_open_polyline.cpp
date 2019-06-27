#include "Simple_Window.h"

void graphics();

int main() try
{
  graphics();
}
catch (exception &e)
{
  return 1;
}
catch (...)
{
  return 2;
}

void graphics()
{
  Point tl{100, 100};
  Simple_window win{tl, 600, 400, "Canvas"};
  Open_polyline opl = {{100, 100}, {150, 200}, {250, 250}, {300, 200}};
  win.attach(opl);
  win.wait_for_button();
}