#include <iostream>
#include <string>
#include <fstream>
#include <regex>

using namespace std;

int main()
{
  ifstream in{"post.txt"};
  if (!in)
  {
    throw runtime_error("not found.");
  }
  regex pat{R"(\w{2}\s*\d{5}(-\d{4})?)"};
  int cnt{0};
  for (string line; getline(in, line);)
  {
    smatch matches;
    if (regex_search(line, matches, pat))
    {
      cout << cnt++ << ": " << matches[0] << endl;
      if (matches[1].matched)
      {
        cout << "\t: " << matches[1] << endl;
      }
    }
  }
}