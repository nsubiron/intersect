#pragma once

namespace intersect {

  class Circle;
  class Geometric;
  class Line;
  class Rectangle;

  class Intersector {
    public:

      static bool intersect(const Line &line0, const Line &line1);

      static bool intersect(const Circle &circle, const Line &line);

      static bool intersect(const Circle &circle0, const Circle &circle1);

      static bool intersect(const Rectangle &rectangle, const Line &line);

      static bool intersect(const Rectangle &rectangle, const Circle &circle);

      static bool intersect(const Rectangle &rectangle0, const Rectangle &rectangle1);
  };

} // namespace intersect
