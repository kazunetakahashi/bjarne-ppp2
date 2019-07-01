#include "Link.h"

#include <iostream>
using std::string;

Link *Link::insert(Link *n)
{
  if (!n)
  {
    return this;
  }
  if (prev)
  {
    n->prev = prev;
    prev->succ = n;
  }
  n->succ = this;
  prev = n;
  return n;
}

Link *Link::add(Link *n)
{
  if (!n)
  {
    return this;
  }
  if (succ)
  {
    succ->prev = n;
    n->succ = succ;
  }
  succ = n;
  n->prev = this;
  return n;
}

Link *Link::erase()
{
  if (prev)
  {
    prev->succ = succ;
  }
  if (succ)
  {
    succ->prev = prev;
  }
  return this;
}

Link *Link::find(const string &str)
{
  if (value == str)
  {
    return this;
  }
  if (succ)
  {
    return succ->find(str);
  }
  return nullptr;
}

void Link::print_all()
{
  std::cout << value << std::endl;
  if (succ)
  {
    succ->print_all();
  }
}