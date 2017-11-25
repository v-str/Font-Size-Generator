#include <doctest.h>

#include <QFont>
#include <QWidget>

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
}
