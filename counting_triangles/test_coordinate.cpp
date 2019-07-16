#include "class_intersectionList.h"
#include <catch2/catch.hpp>

TEST_CASE("Testing coordinate class.", "[coord]"){
  Line l1(2, 2, 4, 2);
  Line l2(3, 1, 3, 4);
  Line l3(2, 3, 4, 1);

  IntersectionList il = {l1, l2, l3};

  // Test that lines actually intersect.
  CHECK(il.checkIntersect(0, 1));
  CHECK(il.checkIntersect(1, 2));
}
