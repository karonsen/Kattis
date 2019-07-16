#ifndef CLASS_INTERSECTION_LIST_H
#define CLASS_INTERSECTION_LIST_H

#include "class_line.h"
#include <stddef.h>
#include <vector>

// Helper class for coordinates of intersections.
class Coordinate {
  double m_x;
  double m_y;

public:
  Coordinate(double x, double y); // : m_x(x), m_y(y) {}
  Coordinate();                   // : coordinate(-1, -1) {}
  double getX();                  // { return m_x; }
  double getY();                  // { return m_y; }
  double distance(Coordinate &);
};

double distance(Coordinate &, Coordinate &);

class IntersectionList {
  // intersections - List over which lines intersect.
  // N - Number of lines in total.
  size_t m_N;
  size_t m_M;
  std::vector<bool> m_intersections;
  std::vector<size_t> m_lineIndices;

public:
  IntersectionList();
  IntersectionList(std::vector<Line> &);
  IntersectionList(std::initializer_list<Line>);
  size_t calculateIntersections(std::vector<Line> &);
  bool checkIntersect(size_t, size_t);

  size_t getIndex(size_t, size_t j);
  size_t getN();
  size_t getM();
  std::vector<bool> getIntersections();
  std::vector<size_t> getLineIndices();
};

#endif /* ifndef CLASS_INTERSECTION_LIST_H */
