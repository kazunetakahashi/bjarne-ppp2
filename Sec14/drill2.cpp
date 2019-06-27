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
  virtual void prv() = 0;
};

class D2 : public B1
{
public:
  void vf() override
  {
    cout << "D2::vf()" << endl;
  }
  void f()
  {
    cout << "D2::f()" << endl;
  }
  void prv() override
  {
    cout << "D2::prv()" << endl;
  }
};

void call(B1 &b)
{
  cout << "call()" << endl;
  b.vf();
  b.f();
  b.prv();
}

class B2
{
public:
  virtual void prv() = 0;
};

class D21 : public B2
{
public:
  D21(string st) : S{st} {}
  void prv() override
  {
    cout << S << endl;
  }

private:
  string S;
};

class D22 : public B2
{
public:
  D22(int k) : a{k} {}
  void prv() override
  {
    cout << a << endl;
  }

private:
  int a;
};

void call(B2 &b)
{
  cout << "call()" << endl;
  b.prv();
}

int main()
{
  D2 d2;
  cout << "d2" << endl;
  d2.vf();
  d2.f();
  d2.prv();
  call(d2);
  D21 d21("test");
  cout << "d21" << endl;
  d21.prv();
  call(d21);
  D22 d22(22);
  cout << "d22" << endl;
  d22.prv();
  call(d22);
}