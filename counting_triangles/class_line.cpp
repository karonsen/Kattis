#include "class_line.h"
#include "class_intersectionList.h"
#include <cmath>

// TODO What if x1, y1 = x2, y2?
Line::Line(double x1, double y1, double x2, double y2)
    : m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2) {}

double Line::getX1() { return m_x1; }
double Line::getX2() { return m_x2; }
double Line::getY1() { return m_y1; }
double Line::getY2() { return m_y2; }

Coordinate Line::intersect(Line &l2) { return ::intersect(*this, l2); }

Coordinate intersect(Line &l1, Line &l2) {

  // Extract from line 1.
  double x1 = l1.getX1();
  double x2 = l1.getX2();
  double y1 = l1.getY1();
  double y2 = l1.getY2();

  // Extract from line 2.
  double x3 = l2.getX1();
  double x4 = l2.getX2();
  double y3 = l2.getY1();
  double y4 = l2.getY2();

  // First determine if the lines are parallel by computing the denominator of
  // the determinant, see https://en.m.wikipedia.org/wiki/Line-line_intersection

  double TOL = 1e-14;
  double den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

  if (fabs(den) < TOL) {
    // If the denominator is zero (approximated by a small value here) the lines
    // are parallel, and in this case considered to not intersect at all. A
    // triangle where two sides are completely overlapping is hardly a triangle.
    return Coordinate();
  }

  // Deduce whether the lines intersect within the line segments or outside
  // them. If t or u becomes larger than 1 or smaller than 0 the intersection
  // happens not on the line segments, but on the infinite lines beyond the
  // segments.
  double t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / den;
  double u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / den;
  if (t > 1 || t < 0 || u > 1 || u < 0) {
    return Coordinate();
  }

  // Calculate coordinates for intersection and return a intersection
  // coordinate.
  double x_in = x1 + t * (x2 - x1);
  double y_in = y1 + t * (y2 - y1);

  return Coordinate(x_in, y_in);
}
