#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

using namespace std::literals;

constexpr inline std::string_view version{"xmadmop 0.0.0"};
constexpr inline std::string_view help_msg{
  "usage:  xmadmop [-options ...]\n"
  "\n"
  "where options include:\n"
  "    -help                        print this usage message\n"
  "    -version                     print program version\n"};

struct Context {
  bool show_help = false;
  bool show_version = false;
  bool has_err = false;
};

class Logger {
 protected:
  std::stringstream ss;
  std::ostream& os;

 public:
  Logger(std::ostream& os): os{os} { ss << "xmadmop: "; }
  ~Logger() { os << ss.str() << '\n'; }
};

class Log: public Logger {
 public:
  Log(): Logger{std::cout} {}

  template<typename T>
  auto operator<<(T&& val) -> Log& {
    ss << std::forward<T>(val);
    return *this;
  }
};

class Err: public Logger {
 public:
  Err(): Logger{std::cerr} {}

  template<typename T>
  auto operator<<(T&& val) -> Err& {
    ss << std::forward<T>(val);
    return *this;
  }
};
