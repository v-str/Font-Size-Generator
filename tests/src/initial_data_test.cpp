#include <stdexcept>
#include <string>

#include <doctest.h>

#include <initial_data.h>

SCENARIO("correct storing and obtaining initial datas") {
  GIVEN("instance of InitialData class and string for error text") {
    InitialData initial_data;
    std::string error_text;

    WHEN(
        "method SetInitialWidgetWidth receive negative widget width size as "
        "parameter") {
      try {
        initial_data.SetInitialWidgetWidth(-100);
      } catch (const std::logic_error& error) {
        error_text = error.what();
      }
      THEN("text of exception should be written") {
        REQUIRE(error_text ==
                std::string("widget sides size must be greater than 0"));
      }
    }
  }
}
