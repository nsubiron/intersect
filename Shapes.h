#pragma once

#include "Vector2D.h"

#include <memory>
#include <vector>
#include <array>

namespace intersect {

  // -- Circle -----------------------------------------------------------------

  class Circle {
    public:

      explicit Circle(const Point &centre, double radius) :
        _centre(centre),
        _radius(radius) {}

      const Point &get_centre() const {
        return _centre;
      }

      double get_radius() const {
        return _radius;
      }

    private:

      Point _centre;

      double _radius;
  };

  // -- Line -------------------------------------------------------------------

  class Line {
    public:

      explicit Line(const Point &begin, const Point &end) :
        _begin(begin),
        _end(end) {}

      const Point &get_begin() const {
        return _begin;
      }

      const Point &get_end() const {
        return _end;
      }

      std::unique_ptr<Direction> get_direction() const;

      double get_length() const;

    private:

      Point _begin;

      Point _end;
  };

  // -- Rectangle --------------------------------------------------------------

  class Rectangle {
    public:

      using corners = std::array<Point, 4u>;

      // Create a rectangle aligned with X and Y axis.
      explicit Rectangle(
          const Point &lower_left_corner,
          const Point &upper_right_corner);

      const corners &get_corners() const {
        return _corners;
      }

    private:

      corners _corners;
  };

} // namespace intersect
