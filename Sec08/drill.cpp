#include <iostream>
using std::cout;
using std::endl;

void swap(int x, int y)
{
  int temp = x;
  x = y;
  y = temp;
}

/* これは通らない。
void swap_cr(const int &x, const int &y)
{
  int temp = x;
  x = y;
  y = temp;
}
*/

void swap_r(int &x, int &y)
{
  int temp = x;
  x = y;
  y = temp;
}

int main()
{
  int x = 7;
  int y = 9;
  const int cx = 7;
  const int cy = 9;
  double dx = 7.7;
  double dy = 9.9;
  cout << "x = " << x << ", y = " << y << endl;
  swap(x, y);
  cout << "x = " << x << ", y = " << y << endl;
  swap(x, y);
  cout << "cx = " << cx << ", cy = " << cy << endl;
  swap(cx, cy);
  cout << "cx = " << cx << ", cy = " << cy << endl;
  swap(cx, cy);
  cout << "dx = " << dx << ", dy = " << dy << endl;
  swap(dx, dy);
  cout << "dx = " << dx << ", dy = " << dy << endl;
  swap(dx, dy);
  cout << "x = " << x << ", y = " << y << endl;
  swap_r(x, y); // これだけ唯一まともに swap する。
  cout << "x = " << x << ", y = " << y << endl;
  swap_r(x, y);
  /* 通らない。
  cout << "cx = " << cx << ", cy = " << cy << endl;
  swap_r(cx, cy);
  cout << "cx = " << cx << ", cy = " << cy << endl;
  swap_r(cx, cy);
  */
  /* 通らない。
  cout << "dx = " << dx << ", dy = " << dy << endl;
  swap_r(dx, dy);
  cout << "dx = " << dx << ", dy = " << dy << endl;
  swap_r(dx, dy);
  */
}