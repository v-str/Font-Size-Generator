#include <doctest.h>

#include <stdexcept>
#include <string>

#include <QFont>
#include <QLabel>
#include <QWidget>

#include <font_size_generator.h>

static const std::string exception_text = "negative value passed as parameter";

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
