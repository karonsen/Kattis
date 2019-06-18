#ifndef CLASS_LINE_H
#define CLASS_LINE_H

class Line{
  double m_x1;
  double m_y1;
  double m_x2;
  double m_y2;

public:
  Line(double, double, double, double);

  double getX1();
  double getX2();
  double getY1();
  double getY2();

  bool intersect(Line &);
};

bool intersect(Line &, Line &);

#endif /* ifndef CLASS_LINE_H */
