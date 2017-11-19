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

SCENARIO("correct initial data getting") {
  GIVEN("instance of class with correct setters methods") {
    InitialData initial_data;
    initial_data.SetInitialWidgetWidth(400);
    initial_data.SetInitialWidgetHeight(600);
    initial_data.SetInitialFontPixelSize(16);
    initial_data.SetFontScaleMultiplier(1.7);

    WHEN("method InitialWidgetWidth called") {
      THEN("the result should be equal 400") {
        int font_width_result = 400;
        REQUIRE(font_width_result == initial_data.InitialWidgetWidth());
      }
    }

    WHEN("method InitialWidgetHeight called") {
      THEN("the result should be equal 600") {
        int font_height_result = 600;
        REQUIRE(font_height_result == initial_data.InitialWidgetHeight());
      }
    }

    WHEN("method InitialFontPixelSize called") {
      THEN("the result should be equal 16") {
        int font_pixel_size_result = 16;
        REQUIRE(font_pixel_size_result == initial_data.InitialFontPixelSize());
      }
    }

    WHEN("method FontScaleMultiplier called") {
      THEN("the result should be equal 1.7") {
        double font_scale_multiplier_result = 1.7;
        REQUIRE(font_scale_multiplier_result ==
                initial_data.FontScaleMultiplier());
      }
    }
  }
}
