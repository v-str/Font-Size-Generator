#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest.h>

#include <QApplication>

int main(int argc, char** argv) {
  doctest::Context context;
  context.applyCommandLine(argc, argv);
  int test_launcher = context.run();

  QApplication app(argc, argv);

  if (context.shouldExit()) {
    return test_launcher = app.exec();
  }
}
