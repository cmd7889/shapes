#include <iostream>
#include <cmath>
#include <vector>
#include "closed_polyline.hpp"
#include "triangle.hpp"
#include "trapezoid.hpp"
#include "polynom.hpp"

using namespace std;


int main() {

    ClosedPolyline poly1({Point(0, 2), Point(13, 42), Point(43, 16)});


    int poly_size = poly1.get_num_vertexes();
    cout << "poly1 size:" << poly_size << endl;
    for (int n = 0; n < poly_size; n++) {

        Point point = poly1[n];

        cout << "point " << n + 1 << endl;
        cout << "x:" << point.get_x() << endl;
        cout << "y:" << point.get_y() << endl;
    }

    cout << "area: " << poly1.area() << endl;


    cout << "=============================" << endl;

    vector<Point> triangle_vertexes = {Point(0, 2), Point(13, 42), Point(43, 16)};
    Triangle triangle1(triangle_vertexes);

    cout << endl << "triangle" << endl;
    for (int n = 0; n < 3; n++) {

        Point point = triangle1[n];

        cout << "point " << n + 1 << endl;
        cout << "x:" << point.get_x() << endl;
        cout << "y:" << point.get_y() << endl;
    }

    cout << "perimeter: " << triangle1.perimeter() << endl;
    cout << "area: " << triangle1.area() << endl;

    cout << "=============================" << endl;

    vector<Point> trapezoid_vertexes = {Point(-1, 2), Point(2, 2), Point(3, 0), Point(-2, 0)};
    Trapezoid trapezoid1(trapezoid_vertexes);

    cout << endl << "trapezoid" << endl;

    for (int n = 0; n < 4; n++) {

        Point point = trapezoid1[n];

        cout << "point " << n + 1 << endl;
        cout << "x:" << point.get_x() << endl;
        cout << "y:" << point.get_y() << endl;
    }

    cout << "perimeter: " << trapezoid1.perimeter() << endl;
    cout << "area: " << trapezoid1.area() << endl;

    try {
        Trapezoid invalid({Point(1, 1), Point(0, 2), Point(0, 0), Point(-5, 3)});
    } catch (invalid_argument e) {
        cout << "Caught exception with message: " << e.what() << endl;
    }

    cout << "=============================" << endl;

    Point point1 = Point(23, 5);
    cout << point1 << '\n';
    Point point2 = Point(43, 48);
    cout << point2 << '\n';
    // оператор присваивания
    Point point3 = point1;
    cout << point3 << '\n';

    Polynom p = {-5, 23, -45, -100};
    cout << p << " where x = 5: " << p(5) << endl;

    return 0;
}
