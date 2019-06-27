#include "Simple_Window.h"

const string pics[4] = {"vegetable_strong.jpg", "fruit_wings.jpg", "fruit_strong.jpg", "vegetable_wings.jpg"};

void graphics();

int main() try
{
  graphics();
}
catch (exception &e)
{
  return 1;
}
catch (...)
{
  return 2;
}

void graphics()
{
  Point tl{100, 100};
  Simple_window win{tl, 800, 1000, "Canvas"};
  win.wait_for_button();
  Lines grid;
  for (auto i = 0; i < 9; i++)
  {
    grid.add(Point{0, i * 100}, Point{800, i * 100});
    grid.add(Point{i * 100, 0}, Point{i * 100, 800});
  }
  win.attach(grid);
  win.wait_for_button();
  Vector_ref<Rectangle> rects;
  for (auto i = 0; i < 8; i++)
  {
    rects.push_back(new Rectangle{Point{100 * i, 100 * i}, 100, 100});
    Rectangle &rect = rects[rects.size() - 1];
    rect.set_fill_color(Color::red);
    win.attach(rect);
  }
  win.wait_for_button();
  Vector_ref<Image> images;
  for (auto i = 0; i < 3; i++)
  {
    images.push_back(new Image{Point{200 + 200 * i, 0}, pics[i]});
    Image &image = images[images.size() - 1];
    image.set_mask(Point{0, 0}, 200, 200);
    win.attach(image);
  }
  win.wait_for_button();
  Image answer{Point{0, 0}, pics[3]};
  answer.set_mask(Point{75, 50}, 100, 100);
  win.attach(answer);
  win.wait_for_button();
  for (auto i = 0; i < 7; i++)
  {
    answer.move(100, 100);
    win.wait_for_button();
  }
}