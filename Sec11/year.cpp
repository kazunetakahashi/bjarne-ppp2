#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
  constexpr static int now = 2019;
  int year;
  cin >> year;
  cout << year << std::hex << '\t' << year << std::oct << '\t' << year << endl;
  cout << std::showbase << std::dec;
  cout << year << std::hex << '\t' << year << std::oct << '\t' << year << endl;
  cout << std::dec << now - year << " years old." << endl;
}