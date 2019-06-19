#include <catch2/catch.hpp>
#include "aux.h"

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

  size_t N1 = lineList1.size();
  size_t N2 = lineList2.size();

  int M1 = countTriangles(il1, N1);
  int M2 = countTriangles(il2, N2);

  CHECK(int1[0] == true);
  CHECK(int1[1] == true);
  CHECK(int1[2] == true);

  CHECK(M1 == 1);
  CHECK(M2 == 1);
}
