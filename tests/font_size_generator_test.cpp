#include <doctest.h>

#include <stdexcept>
#include <string>

#include <QFont>
#include <QLabel>
#include <QWidget>

#include <font_size_generator.h>

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

  GIVEN(
      "correct instance of QLabel with font = 18 pixels and "
      "FontSizeGenerator") {
    QLabel default_label;
    default_label.setGeometry(100, 100, 400, 600);
    QFont font;
    font.setPixelSize(18);
    default_label.setFont(font);

    FontSizeGenerator font_size_generator(2.0, default_label);

    WHEN(
        "method GenerateFontSize called with QLabel pointer which have equal "
        "parameters as default label") {
      QLabel* label = new QLabel;
      label->setGeometry(100, 100, 400, 600);
      font_size_generator.GenerateFontSize(label);

      THEN("generated font size should be equal 18") {
        label->setFont(font_size_generator.GetGeneratedFont());
        REQUIRE(label->font().pixelSize() == 18);
      }
    }
  }
}
