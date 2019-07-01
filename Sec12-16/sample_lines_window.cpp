#include "Lines_window.h"
using namespace Graph_lib;

int graphics();

int main() try
{
  return graphics();
}
catch (exception &e)
{
  cerr << "Exception: " << e.what() << endl;
  return 1;
}
catch (...)
{
  cerr << "Some exception." << endl;
  return 2;
}

int graphics()
{
  Lines_window win{Point{100, 100}, 600, 400, "lines"};
  return gui_main();
}