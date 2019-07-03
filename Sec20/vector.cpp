#include <iostream>
#include <algorithm>
#include <memory>
#include <numeric>

namespace My_vector
{
template <typename T, typename A>
struct vector_base
{
  A alloc;
  T *elem;
  unsigned long sz;
  unsigned long space;
  vector_base(const A &a, unsigned long n = 0) : alloc{a}, elem{alloc.allocate(n)}, sz{0u}, space{n} {}
  vector_base(const vector_base &) = delete;
  vector_base &operator=(const vector_base &) = delete;
  vector_base(vector_base &&);
  vector_base &operator=(vector_base &&);
  ~vector_base()
  {
    alloc.deallocate(elem, space);
  }
};

template <typename T, typename A>
vector_base<T, A>::vector_base(vector_base &&b) : alloc{b.alloc}, elem{b.elem}, sz{b.sz}, space{b.space}
{
  b.elem = nullptr;
  b.sz = b.space = 0;
}

template <typename T, typename A>
vector_base<T, A> &vector_base<T, A>::operator=(vector_base &&b)
{
  swap(*this, b);
  return *this;
}

template <typename T, typename A>
void swap(vector_base<T, A> &x, vector_base<T, A> &y)
{
  vector_base<T, A> tmp{x.alloc, 0};
  tmp.elem = x.elem;
  tmp.sz = x.sz;
  tmp.space = x.space;
  x.alloc = y.alloc;
  x.elem = y.elem;
  x.sz = y.sz;
  x.space = y.space;
  y.alloc = tmp.alloc;
  y.elem = tmp.elem;
  y.sz = y.sz;
  y.space = y.space;
  tmp.elem = nullptr;
  tmp.sz = tmp.space = 0;
}

template <typename T, typename A = std::allocator<T>>
class vector : private vector_base<T, A>
{
public:
  using size_type = unsigned long;
  using value_type = T;
  using iterator = T *;
  using const_iterator = T *;

  vector() : vector_base<T, A>{A{}} {}
  explicit vector(size_type);
  ~vector() {}
  vector(const vector &);
  vector &operator=(const vector &);
  vector(vector &&);
  vector &operator=(vector &&);

  T &operator[](size_type n) { return this->elem[n]; }
  const T &operator[](size_type n) const { return this->elem[n]; }
  T &at(size_type n);

  iterator begin() { return this->elem; };
  const_iterator begin() const { return this->elem; };
  iterator end() { return this->elem + size(); };
  const_iterator end() const { return this->elem + size(); };

  size_type size() const { return this->sz; }
  size_type capacity() const { return this->space; }

  void resize(size_type, T val = T());
  void push_back(const T &);
  void reserve(size_type);
};

template <typename T, typename A>
vector<T, A>::vector(size_type s) : vector_base<T, A>{A{}, s}
{
  std::uninitialized_fill(this->elem, this->elem + size(), T{});
}

template <typename T, typename A>
vector<T, A>::vector(const vector &v)
    : vector<T, A>(v.size())
{
  std::uninitialized_copy(v->elem, v->elem + v.size(), this->elem);
}

template <typename T, typename A>
vector<T, A> &vector<T, A>::operator=(const vector &v)
{
  vector tmp{v};
  swap(*this, tmp);
  return *this;
}

template <typename T, typename A>
vector<T, A>::vector(vector &&v)
{
  swap(*this, v);
}

template <typename T, typename A>
vector<T, A> &vector<T, A>::operator=(vector &&v)
{
  swap(*this, v);
  return *this;
}

template <typename T, typename A>
T &vector<T, A>::at(size_type n)
{
  if (!(0 <= n && n < size()))
  {
    throw std::out_of_range("bad index.");
  }
  return this->elem[n];
}

template <typename T, typename A>
void vector<T, A>::resize(size_type newsize, T val)
{
  reserve(newsize);
  if (size() < newsize)
  {
    std::uninitialized_fill(this->elem + size(), this->elem + newsize, val);
  }
  else
  {
    for (auto i = newsize; i < size(); i++)
    {
      this->alloc.destory(this->elem + i);
    }
  }
  this->space = this->elem + newsize;
}

template <typename T, typename A>
void vector<T, A>::push_back(const T &val)
{
  if (this->space == 0)
  {
    reserve(8);
  }
  else if (size() == this->space)
  {
    reserve(2 * size());
  }
  this->alloc.construct(this->elem + size(), val);
  this->sz++;
}

template <typename T, typename A>
void vector<T, A>::reserve(size_type newalloc)
{
  if (newalloc <= this->space)
  {
    return;
  }
  vector_base<T, A> b(this->alloc, newalloc);
  b.sz = size();
  std::uninitialized_copy(this->elem, this->elem + size(), b.elem);
  for (auto i = 0; i < size(); i++)
  {
    this->alloc.destroy(this->elem + i);
  }
  swap(*this, b);
}
} // namespace My_vector

// a solution for https://atcoder.jp/contests/abc130/tasks/abc130_b

int main()
{
  int N, X;
  std::cin >> N >> X;
  My_vector::vector<int> L(N);
  for (auto i = 0; i < N; i++)
  {
    std::cin >> L[i];
  }
  int ans = 0;
  for (auto i = 0; i <= N; i++)
  {
    if (std::accumulate(L.begin(), L.begin() + i, 0) <= X)
    {
      ++ans;
    }
  }
  std::cout << ans << std::endl;
}