#include "Simple_window.h"

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
  Simple_window win{tl, 600, 400, "Friend"};
  Image ii{Point{50, 50}, "vegetable_wings.jpg"};
  win.attach(ii);
  Polygon poly;
  poly.add(Point{300, 25});
  poly.add(Point{500, 25});
  poly.add(Point{500, 140});
  poly.add(Point{300, 140});
  poly.add(Point{300, 100});
  poly.add(Point{230, 120});
  poly.add(Point{300, 80});
  poly.set_style(Line_style(Line_style::dash, 4));
  win.attach(poly);
  Text t{Point{320, 70}, "How about"};
  t.set_font_size(30);
  t.set_font(Font::times_bold);
  win.attach(t);
  Text u{Point{320, 110}, "a vegetable?"};
  u.set_font_size(30);
  u.set_font(Font::times_bold);
  win.attach(u);
  win.wait_for_button();
}