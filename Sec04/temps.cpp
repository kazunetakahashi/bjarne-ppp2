#include "../std_lib_facilities.h"

int main()
{
  vector<double> temps;
  for (double temp; cin >> temp;)
  {
    temps.push_back(temp);
  }
  double sum{0.0};
  for (double temp : temps)
  {
    sum += temp;
  }
  cout << "average: " << sum / temps.size() << endl;
  sort(temps);
  double mid{0.0};
  if (temps.size() % 2 == 0)
  {
    mid = (temps[temps.size() / 2 - 1] + temps[temps.size() / 2]) / 2;
  }
  else
  {
    mid = temps[temps.size() / 2];
  }
  cout << "median: " << mid << endl;
}