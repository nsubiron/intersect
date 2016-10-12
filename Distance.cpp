#include "Distance.h"

#include "Shapes.h"
#include "Vector2D.h"

namespace intersect {

  static double signed_distance_on_direction(
      const Point &point0,
      const Point &point1,
      const Direction &direction) {
    return
      ((point1.x() - point0.x()) * direction.x()
       +
       (point1.y() - point0.y()) * direction.y());
  }

  double Distance::compute(const Point &point0, const Point &point1) {
    Displacement dis(point0, point1);
    return dis.get_length();
  }

  double Distance::compute(const Line &line, const Point &point) {
    const double signedDistance = signed_distance_on_direction(
        line.get_begin(),
        point,
        *line.get_direction());
    if (signedDistance < 0.0) {
      return Distance::compute(point, line.get_begin());
    } else if (signedDistance > line.get_length()) {
      return Distance::compute(point, line.get_end());
    } else {
      return signedDistance;
    }
  }

} // namespace intersect
