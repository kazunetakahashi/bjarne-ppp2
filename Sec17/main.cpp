#include "Link.h"
#include <iostream>
using std::cout;
using std::endl;

Link *saber;
Link *assassin;

constexpr int C = 10000000;

// RAII でないので不本意だが…
void clear(Link *n)
{
  if (n->next())
  {
    clear(n->next());
  }
  delete n;
}

int main()
{
  for (auto i = 0; i < C; i++)
  {
    saber = new Link{"Artoria"};
    saber->add(new Link{"Nero"});
    saber->add(new Link{"Heroine X"});
    saber->add(new Link{"Okita"});
    saber->add(new Link{"Shiki Ryogi"});
    // cout << "Saber: " << endl;
    // saber->print_all();
    assassin = new Link{"Kojiro"};
    assassin = assassin->insert(new Link{"Izo"});
    assassin = assassin->insert(new Link{"Gray"});
    assassin = assassin->insert(new Link{"Jack"});
    // cout << "Assassin: " << endl;
    // assassin->print_all();
    //名前を補足する。
    Link *p = saber->find("Shiki Ryogi");
    if (p)
    {
      p->value = "Shiki Ryogi (Saber)";
    }
    // 正しい場所に移動する。
    Link *p2 = saber->find("Heroine X");
    if (p2)
    {
      p2->erase();
      assassin->add(p2);
    }
    if (i < C - 1)
    {
      clear(saber);
      clear(assassin);
    }
  }
  cout << "Saber: " << endl;
  saber->print_all();
  cout << "Assassin: " << endl;
  assassin->print_all();
}