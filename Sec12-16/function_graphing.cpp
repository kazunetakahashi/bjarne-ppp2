#include "Simple_Window.h"
#include "Graph.h"

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

double one(double)
{
  return 1;
}

double slope(double x)
{
  return x / 2;
}

double square(double x)
{
  return x * x;
}

void graphics()
{
  constexpr int x_max = 600;
  constexpr int y_max = 400;
  Simple_window win{Point{100, 100}, x_max, y_max, "Function graphing"};
  constexpr int r_min = -10;
  constexpr int r_max = 11;
  constexpr int x_orig = x_max / 2;
  constexpr int y_orig = y_max / 2;
  const Point orig{x_orig, y_orig};
  constexpr int x_scale = 30;
  constexpr int y_scale = 30;
  constexpr int n_points = 400;
  Function s{one, r_min, r_max, orig, n_points, x_scale, y_scale};
  Function s2{slope, r_min, r_max, orig, n_points, x_scale, y_scale};
  Function s3{square, r_min, r_max, orig, n_points, x_scale, y_scale};
  win.attach(s);
  win.attach(s2);
  win.attach(s3);
  win.wait_for_button();
  constexpr int x_length = x_max - 40;
  constexpr int y_length = y_max - 40;
  Axis x{Axis::x, Point{20, y_orig}, x_length, x_length / x_scale, "one notch == 1"};
  Axis y{Axis::y, Point{x_orig, y_length + 20}, y_length, y_length / y_scale, "one notch == 1"};
  win.attach(x);
  win.attach(y);
  Text ts{Point{100, y_orig - 40}, "one"};
  Text ts2{Point{100, y_orig + y_orig / 2 - 20}, "x/2"};
  Text ts3{Point{x_orig - 100, 20}, "x^2"};
  win.attach(ts);
  win.attach(ts2);
  win.attach(ts3);
  win.label("Function graphing with label");
  win.wait_for_button();
}