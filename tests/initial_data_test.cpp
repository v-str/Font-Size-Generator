#include <doctest.h>

#include <initial_data.h>

SCENARIO("correct initial data setting") {
  GIVEN("instance of InitialData class") {
    InitialData initial_data;

    WHEN("method SetInitialWidgetWidth receive negative value") {
      initial_data.SetInitialWidgetWidth(-100);
      THEN("initial widget width should be set to 0") {
        int initial_widget_width = 0;
        REQUIRE(initial_widget_width == initial_data.InitialWidgetWidth());
      }
    }

    WHEN("method SetInitialWidgetHeight receive negative value") {
      initial_data.SetInitialWidgetHeight(-1);
      THEN("initial widget height should be set to 0") {
        int initial_widget_height = 0;
        REQUIRE(initial_widget_height == initial_data.InitialWidgetHeight());
      }
    }

    WHEN("method SetInitialFontPixelSize receive negative value") {
      initial_data.SetInitialFontPixelSize(-33);
      THEN("initial widget font pixel size should be set to 0") {
        int initial_widget_font_pixel_size = 0;
        REQUIRE(initial_widget_font_pixel_size ==
                initial_data.InitialFontPixelSize());
      }
    }

    WHEN(
        "method SetFontScaleMultiplier receive negative value as "
        "parameter") {
      initial_data.SetFontScaleMultiplier(-1.9);
      THEN("font scale multiplier should be set to 0.0") {
        int font_scale_multiplier = 0.0;
        REQUIRE(font_scale_multiplier == initial_data.FontScaleMultiplier());
      }
    }
  }
}
