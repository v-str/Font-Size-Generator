#include <stdexcept>
#include <string>

#include <doctest.h>

#include <initial_data.h>

SCENARIO("correct storing and obtaining initial data") {
  GIVEN("instance of InitialData class") {
    InitialData initial_data;

    WHEN("method SetInitialWidgetWidth receive negative value") {
      THEN("exception should be thrown") {
        REQUIRE_THROWS_AS(initial_data.SetInitialWidgetWidth(-100),
                          const std::exception&);
      }
    }

    WHEN("method SetInitialWidgetWidth receive 0 as parameter") {
      THEN("exception should be thrown") {
        REQUIRE_THROWS_AS(initial_data.SetInitialWidgetWidth(0),
                          const std::exception&);
      }
    }

    WHEN("method SetInitialWidgetHeight receive negative value") {
      THEN("exception should be thrown") {
        REQUIRE_THROWS_AS(initial_data.SetInitialWidgetHeight(-100),
                          const std::exception&);
      }
    }

    WHEN("method SetInitialWidgetHeight receive 0 as parameter") {
      THEN("exception should be thrown") {
        REQUIRE_THROWS_AS(initial_data.SetInitialWidgetHeight(0),
                          const std::exception&);
      }
    }

    WHEN("method SetInitialFontPixelSize receive negative value") {
      THEN("exception should be thrown") {
        REQUIRE_THROWS_AS(initial_data.SetInitialFontPixelSize(-100.5),
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

    WHEN(
        "method SetFontScaleMultiplier called with negative value as "
        "parameter") {
      std::string error_text;
      try {
        initial_data.SetFontScaleMultiplier(-0.1);
      } catch (const std::exception& error) {
        error_text = error.what();
      }

      THEN(
          "exception should be contain \"Font scale multiplier should be "
          "positive or neutral value\"") {
        REQUIRE(
            error_text ==
            std::string(
                "Font scale multiplier should be positive or neutral value"));
      }
    }
  }
}
