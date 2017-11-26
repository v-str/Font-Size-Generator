#include <doctest.h>

#include <QFont>
#include <QSize>

#include <font_size_calculator.h>
#include <initial_widget_data.h>

SCENARIO("font size calculation") {
  GIVEN("instances of InitialWidgetData") {
    QFont font;
    font.setPixelSize(16);

    InitialWidgetData initial_widget_data;
    initial_widget_data.SetFontScaleMultiplier(1.1);
    initial_widget_data.SetInitialWidgetFont(font);
    initial_widget_data.SetInitialWidgetWidth(600);
    initial_widget_data.SetInitialWidgetHeight(400);

    WHEN(
        "when current size increased more in width, than on height "
        "and method CalculateCurrentFontSize of FontSizeCalculator called") {
      QSize current_size;
      current_size.setWidth(800);
      current_size.setHeight(550);

      FontSizeCalculator font_size_calculator;
      int result_font_size = font_size_calculator.CalculateCurrentFontSize(
          current_size, initial_widget_data);

      THEN("result font size should be equal 29") {
        REQUIRE(result_font_size == 29);
      }
    }

    WHEN(
        "when current size increased more in height, than on width "
        "and method CalculateCurrentFontSize of FontSizeCalculator called") {
      QSize current_size;
      current_size.setWidth(500);
      current_size.setHeight(770);

      FontSizeCalculator font_size_calculator;
      int result_font_size = font_size_calculator.CalculateCurrentFontSize(
          current_size, initial_widget_data);

      THEN("result font size should be equal 41") {
        REQUIRE(result_font_size == 41);
      }
    }
  }
}
