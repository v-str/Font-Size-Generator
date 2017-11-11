#include <stdexcept>
#include <string>

#include <doctest.h>

#include <initial_data.h>

SCENARIO("correct storing and obtaining initial datas") {
  GIVEN("integer number that contains negative widget width size") {
    int negative_widget_width = -100;

    WHEN(
        "method SetInitialWidgetWidth of InitialData class receive\n"
        "\t    negative widget width size as parameter") {
      InitialData initial_data;
      std::string error_text;
      try {
        initial_data.SetInitialWidgetWidth(negative_widget_width);
      } catch (const std::logic_error& error) {
        error_text = error.what();
      }
      THEN("text of exception should be thrown") {
        REQUIRE(error_text ==
                std::string("widget sides size must be greater than 0"));
      }
    }
  }
}
