#pragma once

#include <cmath>
#include <limits>

namespace intersect {

namespace detail {

  constexpr double LIMITS_EPSILON = std::numeric_limits<double>::epsilon();

}

  constexpr bool is_zero(double x, double scale = 1.0) {
    return std::abs(x) < scale * detail::LIMITS_EPSILON;
  }

  constexpr bool are_equal(double x, double y, double scale = 1.0) {
    return is_zero(x - y, scale);
  }

  constexpr bool is_less_equal(double x, double y, double scale = 1.0) {
    return x <= y + scale * detail::LIMITS_EPSILON;
  }

  constexpr bool is_in_range(double value, double minimum, double maximum, double scale = 1.0) {
    return
        (minimum - scale * detail::LIMITS_EPSILON <= value)
        &&
        (value <= maximum + scale * detail::LIMITS_EPSILON);
  }

} // namespace intersect
