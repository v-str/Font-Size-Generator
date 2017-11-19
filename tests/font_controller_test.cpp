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
        "method SetInitialWidgetMeasurements called with negative scale "
        "multiplier") {
      double font_scale_multiplier = -0.3;

      THEN("exception should be thrown") {
        REQUIRE_THROWS_AS(font_controller.SetInitialWidgetMeasurements(
                              font_scale_multiplier, label),
                          const std::exception&);
      }
    }
  }
  QApplication::exit();
}
