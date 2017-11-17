#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest.h>

int main(int argc, char** argv) {
  doctest::Context context;
  context.applyCommandLine(argc, argv);
  int test_launcher = context.run();

  if (context.shouldExit()) {
    return test_launcher;
  }
}
