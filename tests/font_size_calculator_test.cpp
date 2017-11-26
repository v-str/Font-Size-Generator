#include <doctest.h>

#include <QFont>
#include <QSize>

#include <font_size_calculator.h>
#include <initial_widget_data.h>

SCENARIO("font size calculation") {
  GIVEN("instances of QSize and InitialWidgetData") {
    QSize current_size;
    InitialWidgetData initial_widget_data;

    current_size.setWidth(800);
    current_size.setHeight(600);

    QFont font;
    font.setPixelSize(16);

    initial_widget_data.SetFontScaleMultiplier(1.1);
    initial_widget_data.SetInitialWidgetFont(font);
    initial_widget_data.SetInitialWidgetWidth(600);
    initial_widget_data.SetInitialWidgetHeight(400);

    WHEN("method CalculateCurrentFontSize called with this parameters") {
      FontSizeCalculator font_size_calculator;
      int result_font_size = font_size_calculator.CalculateCurrentFontSize(
          current_size, initial_widget_data);

      THEN("result font size should be equal 20") {
        REQUIRE(result_font_size == 20);
      }
    }
  }
}
