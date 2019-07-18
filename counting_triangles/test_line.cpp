#include "class_intersectionList.h"
#include "class_line.h"
#include <catch2/catch.hpp>

TEST_CASE("Testing class Line", "[Line]") {

  // Create line objects.
  Line l1(-1, 0, 1, 0);
  Line l2(0, -1, 0, 1);
  Line l3(0, -1, 0, 1);
  Line l4(2, 2, 3, 2);
  Line l5(10, 10, 11, 11);
  Line l6(2, 1, 3, 1);

  // Getting coordinates.
  CHECK(l1.getX1() == -1);
  CHECK(l1.getX2() == 1);
  CHECK(l1.getY1() == 0);
  CHECK(l1.getY2() == 0);
  CHECK(l2.getX1() == 0);
  CHECK(l2.getX2() == 0);
  CHECK(l2.getY1() == -1);
  CHECK(l2.getY2() == 1);

  // Checking intersections using intersect(Line, Line).
  CHECK(intersect(l1, l2).intersect() == true);
  CHECK(intersect(l2, l1).intersect() == true);
  CHECK(intersect(l2, l3).intersect() == false);
  CHECK(intersect(l1, l4).intersect() == false);
  CHECK(intersect(l1, l1).intersect() == false);
  CHECK(intersect(l5, l6).intersect() == false);

  // Checking intersections using Line::intersect(Line).
  CHECK(l1.intersect(l2).intersect() == true);
  CHECK(l1.intersect(l4).intersect() == false);
  CHECK(l2.intersect(l1).intersect() == true);
  CHECK(l2.intersect(l3).intersect() == false);
}
