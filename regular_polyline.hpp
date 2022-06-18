#ifndef PR_1_REGULAR_POLYLINE_HPP
#define PR_1_REGULAR_POLYLINE_HPP

#include "polygon.hpp"

// правильный многоульник
class RegularPolygon : public  Polygon {
public:
    RegularPolygon(vector<Point> vs) : Polygon(vs) {
        float side_length = get_distance(vertexes[0], vertexes[1]);
        for (int i = 1; i < vertexes.size() - 1; ++i) {
            if (side_length != get_distance(vertexes[i], vertexes[i + 1])) {
                throw invalid_argument("All sides must be equal");
            };
        }
    }
};

#endif //PR_1_REGULAR_POLYLINE_HPP
