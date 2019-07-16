#include "class_intersectionList.h"
#include <catch2/catch.hpp>

TEST_CASE("Testing coordinate class.", "[coord]") {
  Coordinate c1 = Coordinate(2, 3);
  Coordinate c2 = Coordinate();
  Coordinate c3 = Coordinate(2, 3);

  c3.setX(4);
  c3.setY(1);

  CHECK(c1.getX() == 2);
  CHECK(c1.getY() == 3);
  CHECK(c1.intersect() == true);
  CHECK(c2.getX() == -1);
  CHECK(c2.getY() == -1);
  CHECK(c2.intersect() == false);
  CHECK(c3.getX() == 4);
  CHECK(c3.getY() == 1);
}

TEST_CASE("Testing coordinate class in context.", "[coord2]") {
  Line l1(2, 2, 4, 2);
  Line l2(3, 1, 3, 4);
  Line l3(2, 3, 4, 1);

  IntersectionList il = {l1, l2, l3};

  // Test that lines actually intersect.
  CHECK(il.checkIntersect(0, 1));
  CHECK(il.checkIntersect(1, 2));
}
