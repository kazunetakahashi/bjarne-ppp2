#include "en_de.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
  const unsigned int n_char = 2 * sizeof(int);
  const unsigned int k_char = 2 * n_char;
  string in_file;
  string out_file;
  string key;
  cout << "input in_file out_file key" << endl;
  cin >> in_file >> out_file >> key;
  while (key.size() < k_char)
  {
    key += '0';
  }
  ifstream in_ss{in_file};
  ofstream out_ss{out_file};
  if (!in_ss || !out_ss)
  {
    runtime_error("bad file name.");
  }
  const unsigned int *k = reinterpret_cast<const unsigned int *>(key.data());
  unsigned int out_ptr[2];
  char in_buf[n_char];
  unsigned int *in_ptr = reinterpret_cast<unsigned int *>(in_buf);
  int cnt = 0;
  while (in_ss.get(in_buf[cnt]))
  {
    out_ss << hex;
    if (++cnt == n_char)
    {
      encipher(in_ptr, out_ptr, k);
      out_ss << setw(8) << setfill('0') << out_ptr[0] << " "
             << setw(8) << setfill('0') << out_ptr[1] << " ";
      cnt = 0;
    }
  }
  if (cnt)
  {
    while (cnt != n_char)
    {
      in_buf[cnt++] = '0';
      encipher(in_ptr, out_ptr, k);
      out_ss << out_ptr[0] << " " << out_ptr[1] << " ";
    }
  }
}