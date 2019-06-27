#ifndef Vector_ref_HEADER
#define Vector_ref_HEADER

#include <vector>
using std::vector;

template <typename T>
class Vector_ref
{
  vector<T *> v;
  vector<T *> owned;
  Vector_ref() {}
  // Vector_ref(T *a, T *b = 0, T *c = 0, T *d = 0);
  ~Vector_ref()
  {
    for (size_t i = 0; i < owned.size(); i++)
    {
      delete owned[i];
    }
  }
  void push_back(T &s)
  {
    v.push_back(&s);
  }
  void push_back(T *p)
  {
    v.push_back(p);
    owned.push_back(p);
  }
  T &operator[](int i)
  {
    return *v[i];
  }
  const T &operator[](int i) const
  {
    return *v[i];
  }
  size_t size() const
  {
    return v.size();
  }
};

#endif // Vector_ref_HEADER