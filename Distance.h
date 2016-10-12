#pragma once

namespace intersect {

  class Line;
  class Point;

  class Distance {
    public:

      static double compute(const Point &point0, const Point &point1);

      static double compute(const Line &line, const Point &point);
  };

} // namespace intersect
