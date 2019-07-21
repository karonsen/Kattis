#include "aux.h"
#include "class_line.h"
#include <catch2/catch.hpp>
#include <iostream>

TEST_CASE("Testing countTriangles.", "[countTriangles]") {
  Line l1(1, 1, 2, 1);
  Line l2(1.5, 0.5, 1.5, 2.5);
  Line l3(0.5, 2, 1.5, 0.5);

  Line l4(2, 2, 4, 2);
  Line l5(2, 4, 4, 1);
  Line l6(3, 5, 3, 1);

  std::vector<Line> lineList1 = {l1, l2, l3};
  std::vector<Line> lineList2 = {l4, l5, l6};
  IntersectionList il1(lineList1);
  IntersectionList il2(lineList2);

  std::vector<bool> int1 = il1.getIntersections();
  std::vector<bool> int2 = il2.getIntersections();

  int M1 = countTriangles(il1);
  int M2 = countTriangles(il2);

  CHECK(int1[0] == true);
  CHECK(int1[1] == true);
  CHECK(int1[2] == true);

  CHECK(M1 == 1);
  CHECK(M2 == 1);
}

TEST_CASE("Testing two triangles.", "[countTriangles2]") {
  Line l1(1, 2, 10, 2);
  Line l2(2, 1, 2, 10);
  Line l3(1, 10, 10, 1);
  Line l4(1, 4, 4, 4);
  Line l5(1, 3, 4, 5);

  // Gives this approximately:
  //   \|
  //    |\
  //    | \
  //    |  \
  //    |   \
  //    |/   \
  //   /|     \
  // _/_|__    \
  // /  |       \
  //   _|________\_
  //    |         \
  // Which should imply 2 triangles to be found.

  std::vector<Line> lineList = {l1, l2, l3, l4, l5};
  IntersectionList il(lineList);
  int M = countTriangles(il);

  CHECK(M == 2);
}

TEST_CASE("Testing counting triangles in the 'box'.", "[countTrianglesBox]") {
  // The triangles produced by following six lines:
  Line l1(0, 0, 2, 2);
  Line l2(0.5, 0, 0.5, 2);
  Line l3(1.5, 0, 1.5, 2);
  Line l4(2, 0, 0, 2);
  Line l5(0, 0.5, 2, 0.5);
  Line l6(0, 1.5, 2, 1.5);

  // Gives the box:
  //   _\|___|/_
  //     |\ /|
  //     | x |
  //    _|/_\|_
  //    /|   |\
  // This should result in 8 triangles after ignoring the corners of the square.

  std::vector<Line> lineList = {l1, l2, l3, l4, l5, l6};
  IntersectionList il(lineList);
  int M = countTriangles(il);

  CHECK(M == 8);
}

TEST_CASE("Testing provided test case.", "[countTrianglesSampleIn]") {
  Line l1(1.350, 1.890, 3.825, 3.330);
  Line l2(3.915, 1.575, 2.385, 3.690);
  Line l3(1.350, 2.295, 4.545, 1.845);
  Line l4(2.250, 1.710, 4.140, 3.060);
  Line l5(2.250, 3.150, 3.465, 1.755);

  IntersectionList il = {l1, l2, l3, l4, l5};

  int M = countTriangles(il);
  std::vector<bool> insec = il.getIntersections();
  std::cout << "Test case intersections: ";
  for (auto e : insec) {
    std::cout << e << " ";
  }
  std::cout << std::endl;

  CHECK(M == 4);
}
