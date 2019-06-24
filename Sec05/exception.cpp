#include "../std_lib_facilities.h"

int area(int h, int w)
{
  if (!(h >= 0 && w >= 0))
  {
    throw runtime_error("length should be positive.");
  }
  int a = h * w;
  if (!(a > 0))
  {
    throw runtime_error("area should be positive.");
  }
  return a;
}

int framed_area(int h, int w)
{
  constexpr int C = 2;
  return area(h - C, w - C);
}

int main()
{
  try
  {
    int a, b;
    while (cin >> a >> b)
    {
      cout << "area(" << a << ", " << b << ") = " << area(a, b) << endl;
      cout << "framed_area(" << a << ", " << b << ") = " << framed_area(a, b) << endl;
    }
  }
  catch (runtime_error &e)
  {
    cerr << "runtime_error: " << e.what() << endl;
  }
}