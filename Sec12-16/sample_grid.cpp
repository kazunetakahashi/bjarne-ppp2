#include "Simple_Window.h"
// #include "Vector_ref.h"

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
  Vector_ref<Rectangle> rect;
  for (auto i = 0; i < 16; i++)
  {
    for (auto j = 0; j < 16; j++)
    {
      rect.push_back(new Rectangle{Point{i * 20, j * 20}, 20, 20});
      rect[rect.size() - 1].set_fill_color(Color(i * 16 + j));
      win.attach(rect[rect.size() - 1]);
    }
  }
  win.wait_for_button();
}