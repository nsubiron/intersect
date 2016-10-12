#include "Vector2D.h"

#include "Compare.h"

#include <cassert>
#include <cmath>
#include <stdexcept>

namespace intersect {

  double Vector2D::get_length() const {
    return std::sqrt(_x * _x + _y * _y);
  }

  void Vector2D::normalize() {
    const double length = get_length();
    if (is_zero(length))
      throw std::runtime_error("cannot normalize vector of zero length");
    _x /= length;
    _y /= length;
    assert(are_equal(1.0, get_length(), 2.0));
  }

} // namespace intersect
