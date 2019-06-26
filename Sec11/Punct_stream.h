#ifndef Punct_stream_HEADER
#define Punct_stream_HEADER

#include <string>
#include <sstream>

using std::string;

class Punct_stream
{
public:
  Punct_stream(std::istream &is) : source{is}, sensitive{true} {}
  void whitespace(const string &s) { white = s; }
  void add_white(char c) { white += c; }
  bool is_whitespace(char c);
  void case_sensitive(bool b) { sensitive = b; }
  Punct_stream &operator>>(string &s);
  operator bool();

private:
  std::istream &source;
  std::istringstream buffer;
  string white;
  bool sensitive;
};

#endif // Punct_stream_HEADER