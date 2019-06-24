#include "../std_lib_facilities.h"

constexpr double epsilon = 1.0 / 100;

double to_metre(double x, string s)
{
  if (s == "m")
  {
    return x;
  }
  if (s == "cm")
  {
    return x / 100;
  }
  if (s == "in")
  {
    return to_metre(x * 2.54, "cm");
  }
  if (s == "ft")
  {
    return to_metre(x * 12, "in");
  }
  simple_error("I don't know " + s);
  return -1;
}

int main()
{
  double x;
  string s;
  vector<double> metres;
  while (cin >> x >> s)
  {
    metres.push_back(to_metre(x, s));
  }
  sort(metres.begin(), metres.end());
  for (auto x : metres)
  {
    cout << x << endl;
  }
}