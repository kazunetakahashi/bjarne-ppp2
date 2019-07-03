#include <string>
#include <set>
#include <fstream>
#include <iterator>
#include <algorithm>
using std::string;

const string input = "fgoep7_in.txt";
const string output = "fgoep7_out.txt";

int main()
{
  std::ifstream is{input};
  std::ofstream os{output};
  std::set<string> b{
      std::istream_iterator<string>{is}, std::istream_iterator<string>{}};
  std::copy(b.begin(), b.end(), std::ostream_iterator<string>{os, "\n"});
}