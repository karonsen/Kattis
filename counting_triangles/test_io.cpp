#include "io.h"
#include <catch2/catch.hpp>
#include <sstream>

TEST_CASE("Testing input.", "[input]"){

  std::string inputLine1 = "1\n2 3 4 5";
  std::stringstream ss1(inputLine1);
  size_t N;
  std::vector<double> R;


  readInput(ss1, N, R);

  CHECK(N == 1);
  CHECK(R.at(0) == Approx(2));
  CHECK(R.at(1) == Approx(3));
  CHECK(R.at(2) == Approx(4));
  CHECK(R.at(3) == Approx(5));

  std::string inputLine2 = "3\n1 1 1 1\n2 2 2 2\n3 3 3 3";
  std::stringstream ss2(inputLine2);

  readInput(ss2, N, R);

  CHECK(N == 3);
  CHECK(R.at(0) == Approx(1));
  CHECK(R.at(4) == Approx(2));
  CHECK(R.at(8) == Approx(3));

  std::string inputLine3 = "3\n1 1 1 1\n2 2 2 2\n3 3 3 3\n"
                           "2\n1 2 3 4\n4 3 2 1\n"
                           "2\n2 2 2 2\n2 2 2 2\n"
                           "0";
  std::stringstream ss3(inputLine3);

  readInput(ss3, N, R);

  CHECK(N == 3);
  CHECK(R.at(0) == Approx(1));
  CHECK(R.at(4) == Approx(2));
  CHECK(R.at(8) == Approx(3));

  readInput(ss3, N, R);

  CHECK(N == 2);
  CHECK(R.at(0) == Approx(1));
  CHECK(R.at(3) == Approx(4));
  CHECK(R.at(4) == Approx(4));

  readInput(ss3, N, R);

  CHECK(N == 2);
  CHECK(R.at(0) == Approx(2));

  readInput(ss3, N, R);

  CHECK(N == 0);
  CHECK(R.size() == 0);
}
