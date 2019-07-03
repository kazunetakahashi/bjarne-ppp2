#ifndef Document_HEADER
#define Document_HEADER

#include <vector>
#include <list>
#include <iostream>
using std::istream;
using std::list;
using std::vector;

using Line = vector<char>;

class Text_iterator
{
public:
  // https://stackoverflow.com/questions/41044165/the-c-stl-function-find-doesnt-accept-the-iterator-arguments-of-a-user-defi
  using difference_type = std::ptrdiff_t;
  using value_type = char;
  using pointer = char *;
  using reference = char &;
  using iterator_category = std::forward_iterator_tag;

  Text_iterator(list<Line>::iterator ll, Line::iterator pp) : ln{ll}, pos{pp} {}

  char &operator*() { return *pos; }
  Text_iterator &operator++();
  bool operator==(const Text_iterator &other) const { return ln == other.ln && pos == other.pos; }
  bool operator!=(const Text_iterator &other) const { return !(*this == other); }

private:
  list<Line>::iterator ln;
  Line::iterator pos;
};

struct Document
{
  using iterator = Text_iterator;
  using const_iterator = const Text_iterator;

  list<Line> line;
  Document() { line.push_back(Line{}); }

  iterator begin();
  iterator end();
};

istream &operator>>(istream &is, Document &d);

#endif // Document_HEADER