#include <doctest.h>

#include <stdexcept>
#include <string>

#include <QApplication>
#include <QFont>
#include <QWidget>

#include <font_size_generator.h>

static const std::string exception_text = "negative value passed as parameter";

SCENARIO("interception of incorrect initial parameters in constructor") {
  GIVEN("instance of QWidget and error string") {
    QWidget widget;
    std::string error_text;

    WHEN("FontScaleGenerator called with incorrect font scale multiplier") {
      try {
        FontSizeGenerator font_size_generator(-1.98, widget);
      } catch (const std::exception& error) {
        error_text = error.what();
      }

      THEN("should contain \"negative value passed as parameter\"") {
        REQUIRE(error_text == exception_text);
      }
    }

    AND_WHEN("FontSizeGenerator called with incorrect initial widget width") {
      widget.setGeometry(10, 10, -100, 600);
      try {
        FontSizeGenerator font_size_generator(1.0, widget);
      } catch (const std::exception& error) {
        error_text = error.what();
      }

      THEN("should contain \"negative value passed as parameter\"") {
        REQUIRE(error_text == exception_text);
      }
    }

    AND_WHEN("FontSizeGenerator called with incorrect initial widget height") {
      widget.setGeometry(10, 10, 400, -600);
      try {
        FontSizeGenerator font_size_generator(2.0, widget);
      } catch (const std::exception& error) {
        error_text = error.what();
      }

      THEN("should contain \"negative value passed as parameter\"") {
        REQUIRE(error_text == exception_text);
      }
    }

    AND_WHEN(
        "FontSizeGenerator called with incorrect initial widget font size") {
      QFont font;
      font.setPixelSize(-14);
      widget.setFont(font);

      try {
        FontSizeGenerator font_size_generator(1.5, widget);
      } catch (const std::exception& error) {
        error_text = error.what();
      }

      THEN("should contain \"negative value passed as parameter\"") {
        REQUIRE(error_text == exception_text);
      }
    }
  }

  QApplication::exit();
}
