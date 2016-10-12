#include "Intersector.h"

#include "Compare.h"
#include "Distance.h"
#include "Shapes.h"

#include <cassert>
#include <cmath>

namespace intersect {

  // -- Static methods ---------------------------------------------------------

  // Parametrize lines as (begin + t * direction) and find t0 and t1 for the
  // point in which lines intersect. Return false if lines are parallel.
  static bool find_intersection_as_infinite_lines(
      const Line &line0,
      const Line &line1,
      double &t0,
      double &t1) {
    const auto direction0 = line0.get_direction();
    const auto direction1 = line1.get_direction();
    const auto x0  = line0.get_begin().x();
    const auto y0  = line0.get_begin().y();
    const auto dx0 = direction0->x();
    const auto dy0 = direction0->y();
    const auto x1  = line1.get_begin().x();
    const auto y1  = line1.get_begin().y();
    const auto dx1 = direction1->x();
    const auto dy1 = direction1->y();

    const auto det = dx1 * dy0 - dx0 * dy1;
    const auto inverseDet = 1.0 / det;

    if (!std::isfinite(inverseDet)) {
      // Lines are parallel.
      return false;
    }

    const auto dx01 = x0 - x1;
    const auto dy01 = y0 - y1;
    t0 = (dy1 * dx01 - dx1 * dy01) * inverseDet;
    t1 = (dy0 * dx01 - dx0 * dy01) * inverseDet;

    return true;
  }

  // Check whether a point defined by the parametrization of the line (begin
  // + t * direction) lies on the line segment.
  static bool lies_on_line(const Line &line, double t) {
    return is_in_range(t, 0.0, line.get_length());
  }

  // Return the four sides of the rectangle as lines.
  static void get_rectangle_lines(
      const Rectangle &rectangle,
      std::vector<std::unique_ptr<Line>> &lines) {
    lines.reserve(4u);
    auto corners = rectangle.get_corners();
    assert(corners.size() == 4u);
    for (std::size_t i = 0u; i < corners.size(); ++i) {
      const Point &begin = corners[i];
      const Point &end = corners[(i + 1u) % corners.size()];
      lines.emplace_back(new Line(begin, end));
    }
    assert(lines.size() == 4u);
  }

  // Intersect every side of the rectangle with the object given by rhs.
  template <typename T>
  static bool intersect_with_rectangle(
      const Rectangle &rectangle,
      const T &rhs) {
    std::vector<std::unique_ptr<Line>> lines;
    get_rectangle_lines(rectangle, lines);
    for (auto &rectangle_line : lines) {
      if (Intersector::intersect(rhs, *rectangle_line))
        return true;
    }
    return false;
  }

  // -- Intersector ------------------------------------------------------------

  bool Intersector::intersect(const Line &line0, const Line &line1) {
    double s;
    double t;
    if (!find_intersection_as_infinite_lines(line0, line1, s, t))
      return false;
    return lies_on_line(line0, s) && lies_on_line(line1, t);
  }

  bool Intersector::intersect(const Circle &circle, const Line &line) {
    return is_less_equal(
        Distance::compute(line, circle.get_centre()),
        circle.get_radius());
  }

  bool Intersector::intersect(const Circle &circle0, const Circle &circle1) {
    if (are_equal(circle0.get_centre().x(), circle1.get_centre().x()) &&
        are_equal(circle0.get_centre().y(), circle1.get_centre().y())) {
      return are_equal(circle0.get_radius(), circle1.get_radius());
    }
    return is_less_equal(
        Distance::compute(circle0.get_centre(), circle1.get_centre()),
        (circle0.get_radius() + circle1.get_radius()));
  }

  bool Intersector::intersect(const Rectangle &rectangle, const Line &line) {
    return intersect_with_rectangle(rectangle, line);
  }

  bool Intersector::intersect(const Rectangle &rectangle, const Circle &circle) {
    return intersect_with_rectangle(rectangle, circle);
  }

  bool Intersector::intersect(const Rectangle &rectangle0, const Rectangle &rectangle1) {
    std::vector<std::unique_ptr<Line>> lines0, lines1;
    get_rectangle_lines(rectangle0, lines0);
    get_rectangle_lines(rectangle1, lines1);
    for (auto &line0 : lines0) {
      for (auto &line1 : lines1) {
        if (intersect(*line0, *line1))
          return true;
      }
    }
    return false;
  }

} // namespace intersect
