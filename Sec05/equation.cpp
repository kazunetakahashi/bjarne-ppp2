#include <iostream>
#include <iomanip>
#include <tuple>
#include <cmath>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;
using std::tie;
using Equation = std::tuple<double, double, double>;
using Solution = std::tuple<double, double>;

constexpr double epsilon = 1e-10;

bool almost(double x, double y)
{
  return std::abs(x - y) < epsilon;
}

bool is_solution(const Equation &e, double x)
{
  double a, b, c;
  tie(a, b, c) = e;
  return almost(a * x * x + b * x + c, 0);
}

bool is_solution(const Equation &e, const Solution &s)
{
  double s0, s1;
  tie(s0, s1) = s;
  return is_solution(e, s0) && is_solution(e, s1);
}

Solution solve(const Equation &e)
{
  double a, b, c;
  tie(a, b, c) = e;
  if (almost(a, 0))
  {
    throw runtime_error("a is nearly 0.");
  }
  double h = b * b - 4 * a * c;
  if (h < 0)
  {
    throw runtime_error("The solutions are not real numbers.");
  }
  double s = sqrt(h);
  Solution res{Solution((-b + s) / (2 * a), (-b - s) / (2 * a))};
  if (!is_solution(e, res))
  {
    throw runtime_error("The solutions are not good.");
  }
  return res;
}

int main()
{
  double a, b, c;
  while (cin >> a >> b >> c)
  {
    try
    {
      Equation e(a, b, c);
      Solution s{solve(e)};
      double s0, s1;
      tie(s0, s1) = s;
      cout << std::fixed << std::setprecision(12) << s0 << " " << s1 << endl;
    }
    catch (std::exception &e)
    {
      cerr << "Exception: " << e.what() << endl;
    }
  }
}