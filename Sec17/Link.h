#ifndef Link_HEADER
#define Link_HEADER

#include <string>

class Link
{
public:
  std::string value;
  Link(const std::string &v, Link *p = nullptr, Link *s = nullptr)
      : value{v}, prev{p}, succ{s} {};

  Link *insert(Link *n); // this の前に挿入 return n;
  Link *add(Link *n);    // this の後に挿入 return n;
  Link *erase();         // return this;
  Link *find(const std::string &str);
  Link *previous() { return prev; }
  Link *next() { return succ; }
  void print_all();

private:
  Link *prev, *succ;
};

#endif // Link_HEADER