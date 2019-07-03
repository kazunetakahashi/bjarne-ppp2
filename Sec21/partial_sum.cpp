#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

int main()
{
  std::vector<int> V = {2, 3, 4, 5};
  std::vector<int> W(5, 0);
  std::partial_sum(V.begin(), V.end(), W.begin() + 1);
  for (auto i = 0u; i < W.size(); i++)
  {
    std::cout << "W[" << i << "] = " << W[i] << std::endl;
  }
}