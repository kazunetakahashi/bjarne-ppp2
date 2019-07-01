#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int i = 0;
  cout << "The size of int is " << sizeof(i) << endl;
  char c = 'a';
  cout << "The size of char is " << sizeof(c) << endl;
  int *p = &i;
  cout << "The size of int* is " << sizeof(p) << endl;
  bool b = true;
  cout << "The size of bool is " << sizeof(b) << endl;
  double d = 0.0;
  cout << "The size of double is " << sizeof(d) << endl;
  vector<int> v(1000);
  cout << "The size of vector<int>(1000) is " << sizeof(v) << endl;
}