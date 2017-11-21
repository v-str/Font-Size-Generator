#include <doctest.h>

#include <font_size_generator.h>

SCENARIO("Font size generation") {
  GIVEN(
      "instance of FontSizeGenerator class, that take "
      "initial widget width, height, font pixel size "
      "and font scale multiplier") {
    FontSizeGenerator(600, 400, 18, 2.2);
  }
}
