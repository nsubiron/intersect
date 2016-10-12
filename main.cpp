#include "Intersector.h"
#include "Shapes.h"
#include "Vector2D.h"

#include <iostream>

using namespace intersect;

int main() {
  const Line line0(Point(-1.0,  1.0), Point(1.0, 1.0));
  const Line line1(Point(-1.0, -1.0), Point(1.0, 1.0));

  const Circle circle0(Point(0.0, 0.0), 1.0);
  const Circle circle1(Point(0.0, 0.0), 2.0);

  const Rectangle rectangle0(Point(-1.0, -1.0), Point(1.0, 1.0));
  const Rectangle rectangle1(Point( 0.0,  0.0), Point(1.0, 2.0));

  std::cout << "line - line: "
            << (Intersector::intersect(line0, line1) ? "yes" : "no")
            << std::endl;
  std::cout << "circle - line: "
            << (Intersector::intersect(circle0, line0) ? "yes" : "no")
            << std::endl;
  std::cout << "circle - circle: "
            << (Intersector::intersect(circle0, circle1) ? "yes" : "no")
            << std::endl;
  std::cout << "rectangle - line: "
            << (Intersector::intersect(rectangle0, line0) ? "yes" : "no")
            << std::endl;
  std::cout << "rectangle - circle: "
            << (Intersector::intersect(rectangle0, circle0) ? "yes" : "no")
            << std::endl;
  std::cout << "rectangle - rectangle: "
            << (Intersector::intersect(rectangle0, rectangle1) ? "yes" : "no")
            << std::endl;
}
