#ifndef Lines_window_HEADER
#define Lines_window_HEADER

#include "Window.h"
#include "Graph.h"
#include "GUI.h"

namespace Graph_lib
{
struct Lines_window : Window
{
  Lines_window(Point xy, int w, int h, const string &title);

private:
  Open_polyline lines;
  Button next_button;
  Button quit_button;
  In_box next_x;
  In_box next_y;
  Out_box xy_out;
  Menu color_menu;
  Button menu_button;

  void change(Color c) { lines.set_color(c); }
  void hide_menu();
  void red_pressed();
  void blue_pressed();
  void black_pressed();
  void menu_pressed();
  void next();
  void quit();

  static void cb_red(Address, Address);
  static void cb_blue(Address, Address);
  static void cb_black(Address, Address);
  static void cb_menu(Address, Address);
  static void cb_next(Address, Address);
  static void cb_quit(Address, Address);
};
} // namespace Graph_lib

#endif // Lines_window_HEADER