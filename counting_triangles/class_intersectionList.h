#ifndef CLASS_INTERSECTION_LIST_H
#define CLASS_INTERSECTION_LIST_H

#include "class_line.h"
#include <stddef.h>
#include <vector>

class IntersectionList{
  // intersections - List over which lines intersect.
  // N - Number of lines in total.
  size_t m_N;
  size_t m_M;
  std::vector<bool> m_intersections;
  std::vector<size_t> m_lineIndices;

public:
  IntersectionList();
  IntersectionList(std::vector<Line> &);
  size_t calculateIntersections(std::vector<Line> &);
  bool checkIntersect(size_t, size_t);

  size_t getIndex(size_t, size_t j);
  size_t getN();
  size_t getM();
  std::vector<bool> getIntersections();
  std::vector<size_t> getLineIndices();
};

#endif /* ifndef CLASS_INTERSECTION_LIST_H */
