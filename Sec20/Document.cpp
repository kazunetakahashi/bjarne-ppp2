#include "Document.h"
#include <iostream>

istream &operator>>(istream &is, Document &d)
{
  for (char ch; is.get(ch);)
  {
    d.line.back().push_back(ch);
    if (ch == '\n')
    {
      d.line.push_back(Line{});
    }
  }
  if (!d.line.back().empty())
  {
    d.line.push_back(Line{});
  }
  return is;
}

Text_iterator &Text_iterator::operator++()
{
  ++pos;
  if (pos == (*ln).end())
  {
    ++ln;
    pos = (*ln).begin();
  }
  return *this;
}

Document::iterator Document::begin()
{
  return Text_iterator(line.begin(), line.begin()->begin());
}

Document::iterator Document::end()
{
  auto last = line.end();
  --last;
  return Text_iterator(last, last->end());
}
