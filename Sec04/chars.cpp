#include "../std_lib_facilities.h"

int main()
{
  constexpr int C = 26;
  for (auto i = 0; i < C; i++)
  {
    cout << char('A' + i) << '\t' << int('A' + i) << endl;
  }
  for (auto i = 0; i < C; i++)
  {
    cout << char('a' + i) << '\t' << int('a' + i) << endl;
  }
  for (auto i = 0; i < 128; i++)
  {
    cout << i << '\t' << char(i) << endl;
  }
}