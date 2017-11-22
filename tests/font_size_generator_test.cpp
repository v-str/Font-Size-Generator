#include <doctest.h>

#include <stdexcept>

#include <QApplication>
#include <QSize>

#include <font_size_generator.h>

SCENARIO("Getting correct initial parameters") {
  GIVEN("negative initial widget font pixel size") {
    double negative_widget_font_pixel_size = -1.78;

    WHEN("this parameter passed into FontSizeGenerator constructor") {
      THEN("exception should be thrown") {
        REQUIRE_THROWS_AS(
            FontSizeGenerator font_size_generator(
                negative_widget_font_pixel_size, 1.1, QSize(100, 100)),
            const std::logic_error&);
      }
    }
  }

  QApplication::exit();
}
