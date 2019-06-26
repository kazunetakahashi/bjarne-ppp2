#include <iostream>
using std::cout;
using std::endl;

namespace X
{
int var;
void print()
{
  cout << var << endl;
}
} // namespace X

namespace Y
{
int var;
void print()
{
  cout << var << endl;
}
} // namespace Y

namespace Z
{
int var;
void print()
{
  cout << var << endl;
}
} // namespace Z

int main()
{
  X::var = 7;
  X::print();
  using namespace Y;
  var = 9;
  print();
  {
    using Z::print;
    using Z::var;
    var = 11;
    print();
  }
  print();
  X::print();
}