#include <stdexcept>
#include <string>

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
      THEN("exception should be thrown") {
        REQUIRE_THROWS_AS(initial_data.SetInitialFontPixelSize(-100.5),
                          const std::exception&);
      }
    }

    WHEN(
        "method SetFontScaleMultiplier receive negative value as "
        "parameter") {
      THEN("exception should be thrown") {
        REQUIRE_THROWS_AS(initial_data.SetFontScaleMultiplier(-1.0),
                          const std::exception&);
      }
    }

    WHEN(
        "method SetFontScaleMultiplier receive negative value as "
        "parameter") {
      std::string error_text;
      try {
        initial_data.SetFontScaleMultiplier(-0.1);
      } catch (const std::exception& error) {
        error_text = error.what();
      }

      THEN(
          "exception should be contain \"Font scale multiplier should be "
          "positive or neutral value\"") {
        REQUIRE(
            error_text ==
            std::string(
                "Font scale multiplier should be positive or neutral value"));
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
