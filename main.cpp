#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

#include <QApplication>

#include <font_size_generator.h>

int main(int argc, char** argv) {
  doctest::Context context;
  QApplication app(argc, argv);
  context.applyCommandLine(argc, argv);
  int result_of_tests = context.run();
  if (context.shouldExit()) {
    int qt_app_exec_result = app.exec();
    return result_of_tests + qt_app_exec_result;
  }
}
