#pragma once

namespace intersect {

  // -- Vector2D ---------------------------------------------------------------

  class Vector2D {
    public:

      constexpr double x() const {
        return _x;
      }

      constexpr double y() const {
        return _y;
      }

    protected:

      constexpr explicit Vector2D(double x, double y) : _x(x), _y(y) {}

      double get_length() const;

      void normalize();

    private:

      double _x;

      double _y;
  };

  // -- Point ------------------------------------------------------------------

  class Point : public Vector2D {
    public:

      constexpr explicit Point(double x, double y) : Vector2D(x, y) {}
  };

  // -- Direction --------------------------------------------------------------

  class Direction : public Vector2D {
    public:

      explicit Direction(double x, double y) : Vector2D(x, y) {
        normalize();
      }

      explicit Direction(const Point &begin, const Point &end) :
        Direction(end.x() - begin.x(), end.y() - begin.y()) {}
  };

  // -- Displacement -----------------------------------------------------------

  class Displacement : public Vector2D {
    public:

      constexpr explicit Displacement(double x, double y) : Vector2D(x, y) {}

      constexpr explicit Displacement(const Point &begin, const Point &end) :
        Displacement(end.x() - begin.x(), end.y() - begin.y()) {}

      using Vector2D::get_length;
  };

} // namespace intersect
