#ifndef PR_1_POLYLINE_H
#define PR_1_POLYLINE_H

//#include <vector>
#include "point.hpp"

// ломаная
class Polyline {

protected:
    vector <Point> vertexes;

public:

    Polyline(vector <Point> vs) {
        for (int i = 0; i < vs.size(); i++) {
            this->vertexes.emplace_back(vs[i]);
        }
    };

    // конструктор копирования
    Polyline(const Polyline &other) {
        this->vertexes.reserve(other.vertexes.size());
        copy(other.vertexes.begin(), other.vertexes.end(), back_inserter(this->vertexes));
    }


    ~Polyline() {
        vertexes.clear();
    };

    unsigned get_num_vertexes() const {
        return vertexes.size();
    };

    const Point &operator[](int index) const {
        return vertexes[index];
    };


    virtual float perimeter() {
        float p = 0;
        for (int i = 0; i < vertexes.size() - 1; i++) {
            p += get_distance(vertexes[i], vertexes[i + 1]);
        }
        return p;
    };

};

#endif //PR_1_POLYLINE_H
