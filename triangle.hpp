#ifndef PR_1_TRIANGLE_HPP
#define PR_1_TRIANGLE_HPP

#include "polygon.hpp"

// треугольник
class Triangle : public Polygon {

public:

    Triangle(vector <Point> vs) : Polygon(vs) {
        if (vertexes.size() != 3) {
            throw invalid_argument("Triangle must have only three points");
        }
    }

    Triangle(Point p1, Point p2, Point p3) : Polygon({p1, p2, p3}) {}

};

bool is_parallel(Point p1, Point p2, Point q1, Point q2) {
    return (p2.get_y() - p1.get_y()) / (p2.get_x() - p1.get_x()) ==
           (q2.get_y() - q1.get_y()) / (q2.get_x() - q1.get_x());
}

#endif //PR_1_TRIANGLE_HPP
