#include "class_intersectionList.h"
#include "class_line.h"
#include <catch2/catch.hpp>
#include <iostream>

TEST_CASE("Testing class IntersectionList.", "[IntersectionList]") {

  // Create lines.
  Line l1(2, 1, 3, 1);
  Line l2(2.5, 0.5, 2.5, 1.5);
  Line l3(2, 4, 3, 4);
  Line l4(2, 4, 2, 3);
  Line l5(10, 10, 11, 11);

  // Create lists of the lines.
  std::vector<Line> lineList1 = {l1, l2};
  std::vector<Line> lineList2 = {l1, l2, l3};
  std::vector<Line> lineList3 = {l1, l2, l3, l4};
  std::vector<Line> lineList4 = {l1, l2, l3, l4, l5, l1, l2, l3, l4, l5};
  std::vector<Line> lineList5 = {l1, l3, l2};

  // Create IntersectionList object.
  IntersectionList il1;
  IntersectionList il2;
  IntersectionList il3;
  IntersectionList il4(lineList4);
  IntersectionList il5(lineList5);

  // Calculate all intersections.
  il1.calculateIntersections(lineList1);
  il2.calculateIntersections(lineList2);
  il3.calculateIntersections(lineList3);
  il4.calculateIntersections(lineList4);

  // Get list of indices for each new line.
  std::vector<size_t> lineIndices2 = il2.getLineIndices();
  std::vector<size_t> lineIndices3 = il3.getLineIndices();
  std::vector<size_t> lineIndices4 = il4.getLineIndices();

  // Perform numerous tests.
  CHECK(lineList1[0].getX1() == 2);

  CHECK(il1.getN() == 2);
  CHECK(il1.getM() == 1);
  CHECK(il1.checkIntersect(0, 1) == true);
  CHECK(il1.getIndex(0, 1) == 0);

  CHECK(lineIndices2[0] == 0);
  CHECK(lineIndices2[1] == 2);
  CHECK(il2.getIndex(0, 1) == 0);
  CHECK(il2.getIndex(0, 2) == 1);
  CHECK(il2.getIndex(1, 2) == 2);

  CHECK(lineIndices3[0] == 0);
  CHECK(lineIndices3[1] == 3);
  CHECK(lineIndices3[2] == 5);
  CHECK(il3.getIndex(0, 1) == 0);
  CHECK(il3.getIndex(1, 2) == 3);
  CHECK(il3.getIndex(1, 3) == 4);
  CHECK(il3.getIndex(2, 3) == 5);
  CHECK(il3.getIndex(3, 2) == 5);

  CHECK(lineIndices4[1] == 9);
  CHECK(lineIndices4[2] == 17);
  CHECK(il4.getM() == 45);
  CHECK(il4.getN() == 10);
  CHECK(lineList4[4].getX1() == 10);
  CHECK(il4.checkIntersect(0, 4) == false);
  CHECK(il4.checkIntersect(0, 1) == true);
  CHECK(il4.checkIntersect(1, 4) == false);

  CHECK(il5.checkIntersect(0, 1) == false);
  CHECK(il5.checkIntersect(0, 2) == true);
}
