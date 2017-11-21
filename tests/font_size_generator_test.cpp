#include <doctest.h>

#include <QApplication>
#include <QSize>

#include <font_size_generator.h>

SCENARIO("Font size generation") {
  GIVEN(
      "instance of FontSizeGenerator class, that take "
      "in constructor initial widget font pixel size = 18,"
      "font scale multiplier = 1.0 and QSize variable, that "
      "take as parameters initial widget width = 600 and "
      "initial widget height = 400") {
    FontSizeGenerator font_size_generator(18, 2.2, QSize(600, 400));

    WHEN("widget width changed to 850 and height changed to 580") {
      int result = font_size_generator.GenerateCurrentFontSize(QSize(850, 580));
      THEN("FontSizeGenerator should be return font size value equal 25") {
        REQUIRE(result == 25);
      }
    }
  }

  QApplication::exit();
}
