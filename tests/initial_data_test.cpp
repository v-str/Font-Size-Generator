#include <doctest.h>

#include <stdexcept>
#include <string>

#include <initial_widget_data.h>

SCENARIO("correct initial data setting") {
  GIVEN("negative font scale multiplier = -1.1") {
    double font_scale_multiplier = -1.1;

    WHEN("method SetFontScaleMultiplier called with this parameter") {
      THEN("exception should contain \"negative value passed as parameter\"") {
        REQUIRE_THROWS_AS(
            InitialWidgetData::SetFontScaleMultiplier(font_scale_multiplier),
            const std::exception&);
      }
    }
  }

  GIVEN("negative widget width = -400") {
    int negative_widget_width = -400;

    WHEN("method SetInitialWidgetWidth called with this parameter") {
      THEN("exception should contain \"negative value passed as parameter\"") {
        REQUIRE_THROWS_AS(
            InitialWidgetData::SetInitialWidgetWidth(negative_widget_width),
            const std::exception&);
      }
    }
  }

  GIVEN("instance of InitialData class") {
    InitialWidgetData initial_data;

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
