#include "class_intersectionList.h"
#include "class_line.h"
#include <cmath>
#include <iostream>

// Class: Coordinate
Coordinate::Coordinate(double x, double y) : m_inter(true), m_x(x), m_y(y) {}
Coordinate::Coordinate() : m_inter(false), m_x(-1), m_y(-1) {}
double Coordinate::getX() { return m_x; }
double Coordinate::getY() { return m_y; }
void Coordinate::setX(double x) { m_x = x; }
void Coordinate::setY(double y) { m_y = y; }
bool Coordinate::intersect() { return m_inter; }

double Coordinate::distance(Coordinate &coord) {
  return ::distance(*this, coord);
}

double distance(Coordinate &coord1, Coordinate &coord2) {
  double dx = pow(coord1.getX() - coord2.getX(), 2);
  double dy = pow(coord1.getY() - coord2.getY(), 2);
  return sqrt(dx + dy);
}

// Class: IntersectionList
IntersectionList::IntersectionList()
    : m_N(0), m_M(0), m_intersections(3, Coordinate()), m_lineIndices(3, 0) {}

IntersectionList::IntersectionList(std::vector<Line> &lines)
    : IntersectionList() {
  this->calculateIntersections(lines);
}

IntersectionList::IntersectionList(std::initializer_list<Line> lines)
    : IntersectionList() {
  std::vector<Line> vec = lines;
  this->calculateIntersections(vec);
}

size_t IntersectionList::calculateIntersections(std::vector<Line> &lines) {

  // First register number of lines.
  m_N = lines.size();

  // Make sure the list is correct size.
  // M - Number of possible unique pairs of lines.
  m_M = m_N * (m_N - 1) / 2;

  // Create vectors.
  // m_lineIndices - Element n corresponds to index of the pair of lines (n+1)
  // 	and (n+2). Subsequent pairs (n+1) and (n+3) follows in sequence until
  // 	last line, where next pair (n+2) and (n+3) follows.
  // m_intersections - Element n corresponds to a pair of lines as described
  // 	above. The value of the element represents whether an intersection
  // 	occurs between the two lines (value true) or not (value false).

  m_lineIndices = std::vector<size_t>(m_N - 1, 0);
  m_intersections = std::vector<Coordinate>(m_M, Coordinate());

  // Step through pairs of lines and determine if they intersect.
  // m - Index for list. Incremented each iteration of the inner loop.
  size_t m = 0;
  for (size_t n1 = 0; n1 < m_N - 1; n1++) {
    m_lineIndices[n1] = m;
    for (size_t n2 = n1 + 1; n2 < m_N; n2++) {
      m_intersections[m] = intersect(lines[n1], lines[n2]);
      m++;
    }
  }

  // Return M for debugging purposes.
  return m_M;
}

bool IntersectionList::checkIntersect(size_t i, size_t j) {
  return m_intersections[getIndex(i, j)].intersect();
}

size_t IntersectionList::getIndex(size_t i, size_t j) {
  size_t m = 0;
  size_t mx = i > j ? i : j;
  size_t mn = i >= j ? j : i;

  m += m_lineIndices[mn];
  m += mx - mn - 1;

  return m;
}

size_t IntersectionList::getN() { return m_N; }
size_t IntersectionList::getM() { return m_M; }
std::vector<bool> IntersectionList::getIntersections() {
  std::vector<bool> vec;
  for (auto &e : m_intersections) {
    vec.push_back(e.intersect());
  }
  return vec;
}
std::vector<size_t> IntersectionList::getLineIndices() { return m_lineIndices; }
