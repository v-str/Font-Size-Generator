#include <doctest.h>

#include <stdexcept>
#include <string>

#include <initial_widget_data.h>

SCENARIO("correct initial data setting") {
  GIVEN("negative font scale multiplier = -1.1") {
    double font_scale_multiplier = -1.1;

    WHEN("method SetFontScaleMultiplier called with this parameter") {
      InitialWidgetData::SetFontScaleMultiplier(font_scale_multiplier);
      THEN("exception should be equal 0") {
        double result = InitialWidgetData::FontScaleMultiplier();
        REQUIRE(result == 0.0);
      }
    }
  }

  GIVEN("positive values") {
    double font_scale_multiplier = 1.1;
    int widget_width = 400;
    int widget_height = 600;
    int font_pixel_size = 14;

    WHEN("this values passed into InitialWidgetData as parameters") {
      InitialWidgetData::SetFontScaleMultiplier(font_scale_multiplier);
      InitialWidgetData::SetInitialWidgetWidth(widget_width);
      InitialWidgetData::SetInitialWidgetHeight(widget_height);

      THEN("method FontScaleMultiplier should return 1.1") {
        REQUIRE(InitialWidgetData::FontScaleMultiplier() == 1.1);
      }

      AND_THEN("method InitialWidgetWidth should return 400") {
        REQUIRE(InitialWidgetData::InitialWidgetWidth() == 400);
      }

      AND_THEN("method InitialWidgetHeight should return 600") {
        REQUIRE(InitialWidgetData::InitialWidgetHeight() == 600);
      }
    }
  }
}
