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
  unsigned int in_ptr[2];
  char out_buf[n_char + 1];
  unsigned int *out_ptr = reinterpret_cast<unsigned int *>(out_buf);
  in_ss.setf(ios_base::hex, ios_base::basefield);
  while (in_ss >> in_ptr[0] >> in_ptr[1])
  {
    decipher(in_ptr, out_ptr, k);
    out_ss << out_buf;
  }
}