#include "xmadmop.hh"

auto show_help(std::ostream& os = std::cout) { os << help_msg; }
auto show_version() { std::cout << version << std::endl; }

auto main(int argc, char* argv[]) -> int {
  std::vector<std::string_view> args{argv, argv + argc};
  Context ctx;

  // argparse
  for(size_t i = 1; i < args.size(); i++) {
    if(args[i] == "-help") {
      ctx.show_help = true;
      continue;
    }
    if(args[i] == "-version") {
      ctx.show_version = true;
      continue;
    }
    Err() << "unrecognized argument " << args[i] << '\n';
    ctx.show_help = true;
    ctx.has_err = true;
    break;
  }

  if(ctx.show_help) {
    if(ctx.has_err) {
      show_help(std::cerr);
      return 1;
    }
    show_help();
    return 0;
  }
  if(ctx.show_version) {
    show_version();
    return 0;
  }

  Log() << "hello, world";
}
