#ifndef en_de_HEADER
#define en_de_HEADER

/**
 * File    : en_de.h
 * Author  : Kazune Takahashi
 * Created : 7/23/2019, 6:32:21 AM
 * Powered by Visual Studio Code
 */

void encipher(const unsigned int *const v, unsigned int *w, const unsigned int *const k)
{
  static_assert(sizeof(int) == 4, "size wrong");
  unsigned int y = v[0];
  unsigned int z = v[1];
  unsigned int sum = 0;
  const unsigned int delta = 0x9E3779B9;
  for (unsigned int n = 32; n > 0u; --n)
  {
    y += (z << 4 ^ z >> 5) + z ^ sum + k[sum & 3];
    sum += delta;
    z += (y << 4 ^ y >> 5) + y ^ sum + k[sum >> 11 & 3];
  }
  w[0] = y;
  w[1] = z;
}

void decipher(const unsigned int *const v, unsigned int *w, const unsigned int *const k)
{
  static_assert(sizeof(int) == 4, "size wrong");
  unsigned int y = v[0];
  unsigned int z = v[1];
  unsigned int sum = 0xC6EF3720;
  const unsigned int delta = 0x9E3779B9;
  for (unsigned int n = 32; n > 0u; --n)
  {
    z -= (y << 4 ^ y >> 5) + y ^ sum + k[sum >> 11 & 3];
    sum -= delta;
    y -= (z << 4 ^ z >> 5) + z ^ sum + k[sum & 3];
  }
  w[0] = y;
  w[1] = z;
}

#endif // en_de_HEADER