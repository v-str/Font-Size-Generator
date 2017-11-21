#include <stdexcept>
#include <string>

#include <doctest.h>

#include <QApplication>
#include <QFont>
#include <QLabel>

#include <font_controller.h>

SCENARIO("font controller initial parameters setting") {
  GIVEN("instace of FontController and QLabel classes") {
    FontController font_controller;
    QLabel label;

    WHEN("font controller called with negative font scale multiplier") {
      std::string error_text;
      try {
        font_controller.SetInitialParameters(-1.0, label);
      } catch (const std::exception& error) {
        error_text = error.what();
      }

      THEN("exception should be thrown") {
        REQUIRE(error_text == "initial parameters was set incorrectly");
      }
    }
  }

  QApplication::exit();
}
