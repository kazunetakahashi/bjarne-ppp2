#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct X
{
  int val;

  void out(const string &s, int num)
  {
    cerr << this << "->" << s << ": " << val << " (" << num << ")" << endl;
  }

  X()
  {
    out("X()", 0);
    val = 0;
  }

  X(int v)
  {
    val = v;
    out("X(int)", val);
  }

  X(const X &x)
  {
    val = x.val;
    out("X(const X&)", val);
  }

  X &operator=(const X &a)
  {
    out("X& operator=(const X&)", a.val);
    val = a.val;
    return *this;
  }

  ~X()
  {
    out("~X()", 0);
  }
};

X copy(X a)
{
  return a;
}

X copy2(X a)
{
  X aa = a;
  return aa;
}

X &ref_to(X &a)
{
  return a;
}

X *make(int i)
{
  X a(i);
  return new X(a);
}

struct XX
{
  X a;
  X b;
};

X glob(2);

int main()
{
  X loc{4};
  X loc2{loc};
  loc = X{5};
  cerr << "copy" << endl;
  loc2 = copy(loc);
  cerr << "copy2" << endl;
  loc2 = copy2(loc);
  cerr << "ref_to" << endl;
  X &r = ref_to(loc);
  r = 20;
  cerr << "make" << endl;
  delete make(7);
  delete make(8);
  cerr << "vector" << endl;
  vector<X> v(4);
  cerr << "struct XX" << endl;
  XX loc4;
  cerr << "new / delete" << endl;
  X *p = new X{9};
  delete p;
  X *pp = new X[5];
  delete[] pp;
  cerr << "end" << endl;
}