#include "Document.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using std::string;

const string filename = "characters.txt";

void print(Document &d)
{
  for (auto &p : d)
  {
    std::cout << p;
  }
}

bool match(Text_iterator first, Text_iterator last, const string &s)
{
  auto it = s.begin();
  while (it != s.end())
  {
    if (first == last)
    {
      return false;
    }
    if (*first != *it)
    {
      return false;
    }
    ++first;
    ++it;
  }
  return true;
}

Text_iterator find_text(Text_iterator first, Text_iterator last, const string &s)
{
  if (s.empty())
  {
    return last;
  }
  char first_char = s[0];
  while (true)
  {
    auto p = std::find(first, last, first_char);
    if (p == last || match(p, last, s))
    {
      return p;
    }
    first = ++p;
  }
}

int main()
{
  Document d;
  std::fstream fst{filename};
  if (!fst)
  {
    throw std::runtime_error("file not found.");
  }
  fst >> d;
  print(d);
  string S;
  while (std::cin >> S)
  {
    if (find_text(d.begin(), d.end(), S) == d.end())
    {
      std::cout << "Not found" << std::endl;
    }
    else
    {
      std::cout << "Found" << std::endl;
    }
  }
}