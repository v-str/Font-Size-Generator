#include <stdexcept>
#include <string>

#include <doctest.h>

#include <QApplication>
#include <QLabel>

#include <font_controller.h>

SCENARIO("correct initial parameters setting") {
  GIVEN("instance of QLabel and instance of FontController") {
    QLabel label;
    FontController font_controller;

    WHEN(
        "method SetInitialParameters called with negative scale "
        "multiplier") {
      double font_scale_multiplier = -0.3;

      THEN("exception should be thrown") {
        REQUIRE_THROWS_AS(
            font_controller.SetInitialParameters(font_scale_multiplier, label),
            const std::exception&);
      }
    }

    WHEN(
        "method SetInitialParameters called with incorrect "
        "widget width") {
      label.setGeometry(10, 10, -100, 100);
      double font_scale_multiplier = 1.0;

      THEN("exception should be thrown") {
        REQUIRE_THROWS_AS(
            font_controller.SetInitialParameters(font_scale_multiplier, label),
            const std::exception&);
      }
    }

    WHEN(
        "method SetInitialParameters called with negative or incorrect "
        "parameters in signature") {
      std::string error_text;
      try {
        font_controller.SetInitialParameters(-0.5, label);
      } catch (const std::exception& error) {
        error_text = error.what();
      }

      THEN(
          "exception should contain \"Incorrect initial widget parameters\" "
          "text") {
        REQUIRE(error_text ==
                std::string("incorrect initial widget parameters"));
      }
    }
  }
  QApplication::exit();
}
