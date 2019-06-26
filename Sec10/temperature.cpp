#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::runtime_error;
using std::string;

struct Reading
{
  int hour;
  double temp;
};

const bool operator<(const Reading &left, const Reading &right)
{
  return left.hour < right.hour;
}

int main()
{
  cout << "Enter input file name: ";
  string i_name;
  cin >> i_name;
  ifstream ist{i_name};
  if (!ist)
  {
    throw runtime_error("can't open input file: " + i_name);
  }
  cout << "Enter output file name: ";
  string o_name;
  cin >> o_name;
  ofstream ost{o_name};
  if (!ost)
  {
    throw runtime_error("can't open output file: " + o_name);
  }
  std::vector<Reading> temps;
  int hour;
  double temp;
  while (ist >> hour >> temp)
  {
    if (!(0 <= hour && hour < 24))
    {
      throw runtime_error("hour out of range: " + std::to_string(hour));
    }
    temps.push_back(Reading{hour, temp});
  }
  std::sort(temps.begin(), temps.end());
  for (auto r : temps)
  {
    ost << "(" << r.hour << ", " << r.temp << ")" << std::endl;
  }
}