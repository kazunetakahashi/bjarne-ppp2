#include "../std_lib_facilities.h"

void f1()
{
  bool c = true;
  if (c)
  {
    cout << "success f1()" << endl;
  }
}

void f2()
{
  string s = "ape";
  bool c = "fool" > s;
  if (c)
  {
    cout << "success f2()" << endl;
  }
}

void f3()
{
  vector<char> c(5);
  for (auto i = 0; i < 5; i++)
  {
    // nothing
  }
  cout << "success f3()" << endl;
}

void f4()
{
  string s{"success f4()"};
  for (auto i = 0U; i < s.size(); i++)
  {
    cout << s[i];
  }
  cout << endl;
}

void f5()
{
  int i = 0;
  int j = 9;
  while (i < j)
  {
    ++i;
  }
  if (i == j)
  {
    cout << "success f5()" << endl;
  }
}

void f6()
{
  int x = 4;
  double y = 5 / narrow_cast<double>(x - 2);
  constexpr double epsilon = 1e-10;
  if (abs(y - 2.5) < epsilon)
  {
    cout << "success f6()" << endl;
  }
}

int main()
{
  try
  {
    f1();
    f2();
    f3();
    f4();
    f5();
    f6();
  }
  catch (exception &e)
  {
    cerr << "error: " << e.what() << endl;
  }
  catch (...)
  {
    cerr << "unknown exception." << endl;
  }
}