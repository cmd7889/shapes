#ifndef PR_1_TRAPEZOID_HPP
#define PR_1_TRAPEZOID_HPP

#include "polygon.hpp"

// трапеция
class Trapezoid : public Polygon {

public:

    Trapezoid(vector <Point> vs) : Polygon(vs) {
        if (vertexes.size() != 4) {
            throw invalid_argument("Trapezoid must have four points");
        }
        if (!is_parallel(vertexes[0], vertexes[1], vertexes[2], vertexes[3]) &&
            !is_parallel(vertexes[0], vertexes[2], vertexes[1], vertexes[3])) {
            throw invalid_argument("Trapezoid must have at least two parallel sides");
        }
    }

};

#endif //PR_1_TRAPEZOID_HPP
