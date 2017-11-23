#include <doctest.h>

#include <stdexcept>
#include <string>

#include <initial_widget_data.h>

SCENARIO("correct initial data setting") {
  GIVEN("negative font scale multiplier = -1.1") {
    double font_scale_multiplier = -1.1;

    WHEN("method SetFontScaleMultiplier called with this parameter") {
      THEN(
          "exception should be thrown and contain \"negative value passed as "
          "parameter\"") {
        REQUIRE_THROWS_AS(
            InitialWidgetData::SetFontScaleMultiplier(font_scale_multiplier),
            const std::exception&);
      }

      AND_THEN("contain \"negative value passed as parameter\"") {
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

      AND_THEN("contain \"negative value passed as parameter\"") {
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

      AND_THEN("contain \"negative value passed as parameter\"") {
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
}
