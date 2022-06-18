#ifndef PR_1_POINT_H
#define PR_1_POINT_H

#include <cmath>

using namespace std;

// точка
class Point {

private:
    float x;
    float y;

public:
    Point(float x, float y) {
        this->x = x;
        this->y = y;
    }

    Point(const Point &other) {
        this->x = other.x;
        this->y = other.y;
    };

    Point &operator=(Point other) {
        x = other.x;
        y = other.y;
        return *this;
    };

    float get_x() const {
        return x;
    }

    float get_y() const {
        return y;
    }

    bool operator==(const Point &rhs) const {
        return x == rhs.x && y == rhs.y;
    }

};

ostream &operator<<(ostream &os, const Point &p) {
    return os << '(' << p.get_x() << ", " << p.get_y() << ')';
}

float get_distance(const Point &point1, const Point &point2) {
    return hypot(point2.get_x() - point1.get_x(),
                 point2.get_y() - point1.get_y());
}

#endif //PR_1_POINT_H
