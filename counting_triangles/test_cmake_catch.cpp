#include <catch2/catch.hpp>

TEST_CASE("Testing Catch2 CMake integration.", "[CMake]") {
  CHECK(2 == 2);
  CHECK(true);
}
