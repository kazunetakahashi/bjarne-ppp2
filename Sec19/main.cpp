#include <iostream>
#include <algorithm>
#include <memory>

template <typename T, typename A>
struct vector_base
{
  A alloc;
  T *elem;
  int sz;
  int space;
  vector_base(const A &a, int n = 0) : alloc{a}, elem{alloc.allocate(n)}, sz{0}, space{n} {}
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
  alloc = b.alloc;
  elem = b.elem;
  sz = b.sz;
  space = b.space;
  b.elem = nullptr;
  b.sz = b.space = 0;
  return *this;
}

template <typename T, typename A = std::allocator<T>>
class vector : private vector_base<T, A>
{
public:
  vector() : vector_base<T, A>{A{}} {}
  explicit vector(int);
  ~vector() {}
  vector(const vector &);
  vector &operator=(const vector &);
  vector(vector &&);
  vector &operator=(vector &&);

  T &operator[](int n) { return this->elem[n]; }
  const T &operator[](int n) const { return this->elem[n]; }
  T &at(int n);

  int size() const { return this->sz; }
  int capacity() const { return this->space; }

  void resize(int, T val = T());
  void push_back(const T &);
  void reserve(int);
};

template <typename T, typename A>
vector<T, A>::vector(int s) : vector_base<T, A>{A{}, s}
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
  std::swap<vector_base<T, A>>(*this, tmp);
  return *this;
}

template <typename T, typename A>
vector<T, A>::vector(vector &&v)
{
  std::swap<vector_base<T, A>>(*this, v);
}

template <typename T, typename A>
vector<T, A> &vector<T, A>::operator=(vector &&v)
{
  std::swap<vector_base<T, A>>(*this, v);
  return *this;
}

template <typename T, typename A>
void vector<T, A>::resize(int newsize, T val)
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
void vector<T, A>::reserve(int newalloc)
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
  std::swap<vector_base<T, A>>(*this, b);
}

int main()
{
  int N, X;
  std::cin >> N >> X;
  vector<int> L;
  for (auto i = 0; i < N; i++)
  {
    int l;
    std::cin >> l;
    L.push_back(l);
  }
  vector<int> D;
  for (auto i = 0; i <= N; i++)
  {
    int sum = 0;
    for (auto j = 0; j < i; j++)
    {
      sum += L[j];
    }
    D.push_back(sum);
  }
  int ans = 0;
  for (auto i = 0; i < D.size(); i++)
  {
    if (D[i] <= X)
    {
      ans++;
    }
  }
  std::cout << ans << std::endl;
}