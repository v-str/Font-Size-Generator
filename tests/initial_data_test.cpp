#include <doctest.h>

#include <stdexcept>
#include <string>

#include <initial_widget_data.h>

SCENARIO("correct initial data setting") {
  GIVEN("negative font scale multiplier = -1.1") {
    double font_scale_multiplier = -1.1;

    WHEN("method SetFontScaleMultiplier called with this parameter") {
      std::string error_text;
      try {
        InitialWidgetData::SetFontScaleMultiplier(font_scale_multiplier);
      } catch (const std::exception& error) {
        error_text = error.what();
      }

      THEN("exception should contain \"negative value passed as parameter\"") {
        REQUIRE(error_text ==
                std::string("negative value passed as parameter"));
      }
    }
  }

  GIVEN("instance of InitialData class") {
    InitialWidgetData initial_data;

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
      THEN("exception should be throw") {
        REQUIRE_THROWS_AS(initial_data.SetInitialFontPixelSize(-35),
                          const std::exception&);
      }
    }
  }
}
