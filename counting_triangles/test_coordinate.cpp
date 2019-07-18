#include "class_intersectionList.h"
#include <catch2/catch.hpp>
#include <cmath>
#include <iostream>

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

  CHECK(distance(c1, c3) == Approx(2 * sqrt(2)));
}

TEST_CASE("Testing coordinate class in context.", "[coord2]") {

  // Three lines intersecting at same point.
  Line l1(2, 2, 4, 2);
  Line l2(3, 1, 3, 4);
  Line l3(2, 3, 4, 1);

  // Some lines that intersect elsewhere.
  Line l4(4, 4, 5, 5);
  Line l5(4, 5, 5, 4);

  IntersectionList il = {l1, l2, l3, l4, l5};
  std::vector<Coordinate> cl = il.getCoordinates();

  // Test that lines actually intersect.
  CHECK(il.checkIntersect(0, 1));
  CHECK(il.checkIntersect(1, 2));

  CHECK(cl.size() == (size_t)10);
  CHECK(distance(cl[0], cl[1]) == 0);
}
