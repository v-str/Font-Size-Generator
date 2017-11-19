#include <stdexcept>
#include <string>

#include <doctest.h>

#include <QApplication>
#include <QLabel>

#include <font_controller.h>

SCENARIO("correct using of font controller class") {
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
        "method SetInitialParameters called with negative or incorrect "
        "parameters in signature") {
      std::string error_text;
      try {
        font_controller.SetInitialParameters(-0.5, label);
      } catch (const std::exception& error) {
        error_text = error.what();
      }

      THEN("exception should contain \"Incorrect initial widget parameters\"") {
        REQUIRE(error_text ==
                std::string("incorrect initial widget parameters"));
      }
    }
  }
  QApplication::exit();
}
