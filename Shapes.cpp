#include "Shapes.h"

#include "Distance.h"

namespace intersect {

  std::unique_ptr<Direction> Line::get_direction() const {
    return std::unique_ptr<Direction>(new Direction(_begin, _end));
  }

  double Line::get_length() const {
    return Distance::compute(_begin, _end);
  }

  Rectangle::Rectangle(
      const Point &lower_left_corner,
      const Point &upper_right_corner) :
    _corners{
      lower_left_corner,
      Point(upper_right_corner.x(), lower_left_corner.y()),
      upper_right_corner,
      Point(lower_left_corner.x(), upper_right_corner.y())
    } {}

} // namespace intersect
