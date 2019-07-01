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

double power(double x, int n)
{
  if (n == 0)
  {
    return 1;
  }
  else if (n % 2 == 1)
  {
    return power(x, n - 1) * x;
  }
  else
  {
    double h = power(x, n / 2);
    return h * h;
  }
}

double fac(int n)
{
  return n ? n * fac(n - 1) : 1;
}

double term(double x, int n)
{
  return power(x, n) / fac(n);
}

double exp_n(double x, int n)
{
  double sum = 0;
  for (auto i = 0; i < n; i++)
  {
    sum += term(x, i);
  }
  return sum;
}

int n_exp;

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
  constexpr int x_length = x_max - 40;
  constexpr int y_length = y_max - 40;
  Axis x{Axis::x, Point{20, y_orig}, x_length, x_length / x_scale, "one notch == 1"};
  Axis y{Axis::y, Point{x_orig, y_length + 20}, y_length, y_length / y_scale, "one notch == 1"};
  win.attach(x);
  win.attach(y);
  win.wait_for_button();
  Function real_exp{exp, r_min, r_max, orig, n_points, x_scale, y_scale};
  real_exp.set_color(Color::blue);
  win.attach(real_exp);
  win.wait_for_button();
  for (n_exp = 0; n_exp < 50; n_exp++)
  {
    ostringstream ss;
    ss << "exp approx n = " << n_exp << endl;
    win.set_label(ss.str());
    Function e{[](double x) { return exp_n(x, n_exp); }, r_min, r_max, orig, n_points, x_scale, y_scale};
    win.attach(e);
    win.wait_for_button();
    win.detach(e);
  }
}
