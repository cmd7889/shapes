#ifndef PR_1_CLOSED_POLYLINE_HPP
#define PR_1_CLOSED_POLYLINE_HPP

#include "polyline.hpp"

// замкнутая ломаная
class ClosedPolyline : public Polyline {

public:

    ClosedPolyline(vector <Point> vs) : Polyline(vs) {
    };

    float perimeter() override {
        float p = 0;
        int i;
        for (i = 0; i < vertexes.size() - 1; i++) {
            p = p + get_distance(vertexes[i], vertexes[i + 1]);
        }
        p = p + get_distance(vertexes[i + 1], vertexes[0]);
        return p;
    }

    double area() {
        float sum = 0;
        unsigned n = get_num_vertexes();
        for (unsigned i = 0; i < n; ++i) {
            sum += vertexes[i].get_x() * vertexes[(i + 1) % n].get_y() -
                   vertexes[i].get_y() * vertexes[(i + 1) % n].get_x();
        }
        return abs(sum / 2);
    }
};

bool orientation(Point p, Point q, Point r) {
    return (r.get_y() - p.get_y()) * (q.get_x() - p.get_x()) >
           (q.get_y() - p.get_y()) * (r.get_x() - p.get_x());
};

bool on_segment(Point s1, Point s2, Point p) {
    return p.get_x() < max(s1.get_x(), s2.get_x()) &&
           p.get_x() > min(s1.get_x(), s2.get_x()) &&
           p.get_y() < max(s1.get_y(), s2.get_y()) &&
           p.get_y() > min(s1.get_y(), s2.get_y());
};

bool is_intersecting(Point p1, Point p2, Point q1, Point q2) {

    if (p1 == q1 || p1 == q2 || p2 == q1 || p2 == q2)
        return false;

    std::vector<bool> orientations{
            orientation(p1, p2, q1),
            orientation(p1, p2, q2),
            orientation(q1, q2, p2),
            orientation(q1, q2, p1)
    };

    if (orientations[0] != orientations[1] &&
        orientations[2] != orientations[3]) {
        return true;
    }

    if (orientations[0] == 0 && on_segment(p1, p2, q1)) {
        return true;
    }

    if (orientations[1] == 0 && on_segment(p1, p2, q2)) {
        return true;
    }

    if (orientations[2] == 0 && on_segment(q1, q2, p1)) {
        return true;
    }

    if (orientations[3] == 0 && on_segment(q1, q2, p2)) {
        return true;
    }

    return false;
}


#endif //PR_1_CLOSED_POLYLINE_HPP
