#include <doctest.h>

#include <stdexcept>
#include <string>

#include <initial_widget_data.h>

SCENARIO("correct initial data setting") {
  GIVEN("negative font scale multiplier = -1.1") {
    double font_scale_multiplier = -1.1;

    WHEN("method SetFontScaleMultiplier called with this parameter") {
      THEN("exception should be thrown and contain") {
        REQUIRE_THROWS_AS(
            InitialWidgetData::SetFontScaleMultiplier(font_scale_multiplier),
            const std::exception&);
      }

      AND_THEN("should contain \"negative value passed as parameter\"") {
        std::string error_text;
        try {
          InitialWidgetData::SetFontScaleMultiplier(font_scale_multiplier);
        } catch (const std::exception& error) {
          error_text = error.what();
        }
        REQUIRE(error_text ==
                std::string("negative value passed as parameter"));
      }
    }
  }

  GIVEN("negative widget width = -400") {
    int negative_widget_width = -400;

    WHEN("method SetInitialWidgetWidth called with this parameter") {
      THEN("exception should be thrown") {
        REQUIRE_THROWS_AS(
            InitialWidgetData::SetInitialWidgetWidth(negative_widget_width),
            const std::exception&);
      }

      AND_THEN("should contain \"negative value passed as parameter\"") {
        std::string error_text;
        try {
          InitialWidgetData::SetInitialWidgetWidth(negative_widget_width);
        } catch (const std::exception& error) {
          error_text = error.what();
        }
        REQUIRE(error_text ==
                std::string("negative value passed as parameter"));
      }
    }
  }

  GIVEN("negative widget height = -550") {
    int negative_widget_height = -550;

    WHEN("method SetInitialWidgetHeight called with this parameter") {
      THEN("exception should be thrown") {
        REQUIRE_THROWS_AS(
            InitialWidgetData::SetInitialWidgetHeight(negative_widget_height),
            const std::exception&);
      }

      AND_THEN("should contain \"negative value passed as parameter\"") {
        std::string error_text;
        try {
          InitialWidgetData::SetInitialWidgetHeight(negative_widget_height);
        } catch (const std::exception& error) {
          error_text = error.what();
        }
        REQUIRE(error_text ==
                std::string("negative value passed as parameter"));
      }
    }
  }

  GIVEN("negative widget font pixel size = -14") {
    int negative_widget_font_pixel_size = -14;

    WHEN("method SetInitialFontPixelSize called with this parameter") {
      THEN("exception should be thrown") {
        REQUIRE_THROWS_AS(InitialWidgetData::SetInitialFontPixelSize(
                              negative_widget_font_pixel_size),
                          const std::exception&);
      }

      AND_THEN("should contain \"negative value passed as parameter\"") {
        std::string error_text;
        try {
          InitialWidgetData::SetInitialFontPixelSize(
              negative_widget_font_pixel_size);
        } catch (const std::exception& error) {
          error_text = error.what();
        }
        REQUIRE(error_text ==
                std::string("negative value passed as parameter"));
      }
    }
  }
}

SCENARIO("correct initial widget data obtaining") {
  GIVEN("positive values") {
    double font_scale_multiplier = 1.1;
    int widget_width = 400;
    int widget_height = 600;
    int font_pixel_size = 14;

    WHEN("this values passed into InitialWidgetData as parameters") {
      InitialWidgetData::SetFontScaleMultiplier(font_scale_multiplier);
      InitialWidgetData::SetInitialWidgetWidth(widget_width);
      InitialWidgetData::SetInitialWidgetHeight(widget_height);
      InitialWidgetData::SetInitialFontPixelSize(font_pixel_size);

      THEN("method FontScaleMultiplier should return 1.1") {
        REQUIRE(InitialWidgetData::FontScaleMultiplier() == 1.1);
      }

      AND_THEN("method InitialWidgetWidth should return 400") {
        REQUIRE(InitialWidgetData::InitialWidgetWidth() == 400);
      }

      AND_THEN("method InitialWidgetHeight should return 600") {
        REQUIRE(InitialWidgetData::InitialWidgetHeight() == 600);
      }

      AND_THEN("method InitialFontPixelSize should return 14") {
        REQUIRE(InitialWidgetData::InitialFontPixelSize() == 14);
      }
    }
  }
}
