#include "Punct_stream.h"

Punct_stream &Punct_stream::operator>>(string &s)
{
  while (!(buffer >> s))
  {
    if (buffer.bad() || !source.good())
    {
      return *this;
    }
    buffer.clear();
    string line;
    std::getline(source, line);
    for (auto &ch : line)
    {
      if (is_whitespace(ch))
      {
        ch = ' ';
      }
      else if (sensitive)
      {
        ch = tolower(ch);
      }
    }
    buffer.str(line);
  }
  return *this;
}

bool Punct_stream::is_whitespace(char c)
{
  for (auto x : white)
  {
    if (x == c)
    {
      return true;
    }
  }
  return false;
}

Punct_stream::operator bool()
{
  return !(source.fail() || source.bad()) && source.good();
}