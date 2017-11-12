#include <stdexcept>
#include <string>

#include <doctest.h>

#include <initial_data.h>

SCENARIO("correct storing and obtaining initial data") {
  GIVEN("instance of InitialData class") {
    InitialData initial_data;

    WHEN(
        "method SetInitialWidgetWidth receive negative widget width size as "
        "parameter") {
      THEN("exception should be thrown") {
        REQUIRE_THROWS_AS(initial_data.SetInitialWidgetWidth(-100),
                          const std::logic_error&);
      }
    }
  }
}
