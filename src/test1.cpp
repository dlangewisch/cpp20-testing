#include <fmt/format.h>
#include <fmt/ranges.h>  // fmt::join
#include <fmt/std.h>     // formatters for optional, variant, etc
#include <fmt/ostream.h> // fmt::streamed

#include <spdlog/spdlog.h>

#include <iostream>
#include <vector>
#include <optional>
#include <variant>

struct Widget {
  int x;
  int y;

  friend std::ostream& operator<<(std::ostream& os, Widget const& w)
  {
    return (os << "Widget(x=" << w.x << ", y=" << w.y << ")");
  }
};


int main() {
  fmt::print("{}\n", "test1");

  std::vector<int> vals {0, 1, 2, 3, 4, 5};
  fmt::print("vals: [{}]\n", fmt::join(vals, ", "));

  std::optional<int> opt = 42;
  std::variant<int, std::string> var = "hello";

  fmt::print("opt: {}\n", opt);
  fmt::print("var: {}\n", var);

  Widget w {.x=1, .y=2};

  fmt::print("w: {}\n", fmt::streamed(w));
  std::cout << "w: " << w << "\n";

  std::cout.put('\n');

  spdlog::set_pattern("[%^%l%$] %v");
  spdlog::info("{}", "test1");
  spdlog::info("vals: [{}]", fmt::join(vals, ", "));
  spdlog::info("opt: {}", opt);
  spdlog::info("var: {}", var);
  spdlog::info("w: {}", fmt::streamed(w));
}
