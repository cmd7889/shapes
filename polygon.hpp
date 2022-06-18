#ifndef PR_1_POLYGON_HPP
#define PR_1_POLYGON_HPP

#include "closed_polyline.hpp"

// многоугольник
class Polygon : public ClosedPolyline {
public:

    Polygon(vector <Point> vs) : ClosedPolyline(vs) {

        if (vertexes.size() < 3) {
            throw invalid_argument("Polygon must have at least three points");
        }
        for (int i = 0; i < vertexes.size() - 1; ++i) {
            for (int j = i; j < vertexes.size() - 1; ++j) {
                if (is_intersecting(vertexes[i], vertexes[i + 1], vertexes[j], vertexes[j + 1])) {
                    throw invalid_argument("Self intersecting segments");
                };
            }
        }
    };
};

#endif //PR_1_POLYGON_HPP
