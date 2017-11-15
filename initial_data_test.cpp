#include <stdexcept>
#include <string>

#include <doctest.h>

#include <initial_data.h>

SCENARIO("correct storing and obtaining initial data") {
  GIVEN("instance of InitialData class") {
    InitialData initial_data;

    WHEN("any setter receive negative value or 0 as parameter") {
      THEN("exception should be thrown") {
        REQUIRE_THROWS_AS(initial_data.SetInitialWidgetWidth(-100),
                          const std::exception&);
        REQUIRE_THROWS_AS(initial_data.SetInitialWidgetWidth(-56),
                          const std::exception&);
        REQUIRE_THROWS_AS(initial_data.SetInitialWidgetWidth(0),
                          const std::exception&);
      }
    }

    WHEN("any setter receive negative value or 0 as parameter") {
      std::string error_text;
      try {
        initial_data.SetInitialWidgetWidth(-10);
        initial_data.SetInitialWidgetHeight(0);
        initial_data.SetInitialFontPixelSize(-1);
      } catch (const std::exception& error) {
        error_text = error.what();
      }

      THEN(
          "exception should contain \"The widget sides size should be greater "
          "than 0\"") {
        REQUIRE(error_text ==
                std::string("The widget sides size should be greater than 0"));
      }
    }

    WHEN(
        "method SetFontScaleMultiplier called with negative value as "
        "parameter") {
      THEN("exception should be thrown") {
        REQUIRE_THROWS_AS(initial_data.SetFontScaleMultiplier(-1.0),
                          const std::exception&);
      }
    }
  }
}
