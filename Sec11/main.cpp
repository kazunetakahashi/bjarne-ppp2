#include "Punct_stream.h"
#include <fstream>
#include <set>

const string s_in = "neverland_in.txt";
const string s_out = "neverland_out.txt";

int main()
{
  std::ifstream ifs{s_in};
  if (!ifs)
  {
    throw std::runtime_error("no input file: " + s_in);
  }
  Punct_stream ps{ifs};
  ps.whitespace(";:,.?!()\"{}<>/!@#$%^&*");
  ps.case_sensitive(true);
  std::set<string> words;
  for (string word; ps >> word;)
  {
    words.insert(word);
  }
  std::ofstream ofs{s_out};
  if (!ofs)
  {
    throw std::runtime_error("no output file: " + s_out);
  }
  for (auto word : words)
  {
    ofs << word << std::endl;
  }
}