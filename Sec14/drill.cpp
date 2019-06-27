#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class B1
{
public:
  virtual void vf()
  {
    cout << "B1::vf()" << endl;
  }
  void f()
  {
    cout << "B1::f()" << endl;
  }
};

class D1 : public B1
{
public:
  void vf() override
  {
    cout << "D1::vf()" << endl;
  }
  void f()
  {
    cout << "D1::f()" << endl;
  }
};

void call(B1 &b)
{
  cout << "call()" << endl;
  b.vf();
  b.f();
}

int main()
{
  B1 b1;
  cout << "b1" << endl;
  b1.vf();
  b1.f();
  call(b1);
  D1 d1;
  cout << "d1" << endl;
  d1.vf();
  d1.f();
  call(d1);
  B1 &b1s = d1;
  cout << "b1s" << endl;
  b1s.vf();
  b1s.f();
  call(b1s);
}