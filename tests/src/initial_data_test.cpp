#include <stdexcept>
#include <string>

#include <doctest.h>

#include <initial_data.h>

SCENARIO("correct storing and obtaining initial data") {
  GIVEN("instance of InitialData class") {
    InitialData initial_data;

    WHEN("method any setter receive negative value or 0 as parameter") {
      THEN("exception should be thrown") {
        REQUIRE_THROWS_AS(initial_data.SetInitialWidgetWidth(-100),
                          const std::exception&);
        REQUIRE_THROWS_AS(initial_data.SetInitialWidgetWidth(-56),
                          const std::exception&);
        REQUIRE_THROWS_AS(initial_data.SetInitialWidgetWidth(0),
                          const std::exception&);
      }
    }
  }
}
