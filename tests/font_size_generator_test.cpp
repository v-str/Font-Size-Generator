#include <doctest.h>

#include <stdexcept>
#include <string>

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
}

SCENARIO("font size generation") {
  GIVEN("correct instance of QWidget and FontSizeGenerator") {
    QWidget widget;
    widget.setGeometry(10, 10, 10, 10);
    QFont font;
    font.setPixelSize(14);
    widget.setFont(font);

    FontSizeGenerator font_size_generator(1.0, widget);

    WHEN("method GenerateFontSize called with null pointer") {
      std::string error_text;
      QWidget* widget_ptr = nullptr;
      try {
        font_size_generator.GenerateFontSize(widget_ptr);
      } catch (const std::exception& error) {
        error_text = error.what();
      }

      THEN("exception should contain \"Null pointer passed as parameter\"") {
        REQUIRE(error_text == std::string("Null pointer passed as parameter"));
      }
    }
  }
}
