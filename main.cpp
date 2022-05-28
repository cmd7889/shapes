#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Point {

private:
    float x;
    float y;

public:
    Point(float x, float y) {
        this->x=x;
        this->y=y;
    }

    Point(const Point &other){
        this->x = other.x;
        this->y = other.y;
    };

    Point& operator=(Point other){
        x= other.x;
        y= other.y;
    };

    float get_x() {
        return x;
    }

    float get_y() {
        return y;
    }

    void print(){
        cout << "x:" << x << " y:" << y << endl;
    };

};


// ломаная
class Polyline {

protected:
    vector<Point> vertexes;

public:

    // конструктор копирования
    Polyline(const Polyline &other) {
        this->vertexes.reserve(other.vertexes.size());
        copy(other.vertexes.begin(), other.vertexes.end(), back_inserter(this->vertexes));
    }

    Polyline() {
        cout << "Empty Polyline constructor"<< endl;
    }

    Polyline(Point points[], unsigned size) {
        cout << "Polyline constructor with array vertexes"<< endl;
        cout << "polyline array size:" << size << endl;
        for (int i = 0; i < size; i++) {
            this->vertexes.emplace_back(points[i]);
        }
    }

    ~Polyline(){
        cout << "Polyline destructor "<< this << endl;
        vertexes.clear();
    }

    void add_vertex(float x, float y) {
        vertexes.emplace_back(x, y);
    }

    unsigned get_num_vertexes() {
        return vertexes.size();
    }

    Point get_vertex(int vertex_num) {
        return vertexes[vertex_num];
    }

    float get_distance(unsigned point1, unsigned point2) {
        return sqrt(pow(vertexes[point1].get_x() - vertexes[point2].get_x(), 2.0f) +
                    pow(vertexes[point1].get_y() - vertexes[point2].get_y(), 2.0f));
    }

    float perimeter() {
        float p = 0;
        for (int i = 0; i < vertexes.size() - 1; i++) {
            p = p + get_distance(i, i + 1);
        }
        return p;
    }

};

// замкнутая ломаная
class ClosedPolyline : public Polyline {

public:

    ClosedPolyline() : Polyline() {
        cout << "ClosedPolyline constructor without parameters"<< endl;
    };

    ClosedPolyline(Point points[], unsigned size) : Polyline(points, size) {
        cout << "ClosedPolyline constructor"<< endl;
    };

    float perimeter()  {
        float p = 0;
        int i;
        for (i = 0; i < vertexes.size() - 1; i++) {
            p = p + get_distance(i, i + 1);
        }
        p = p + get_distance(i + 1, 0);
        return p;
    }

    double area(){
        float sum=0;
        unsigned n = get_num_vertexes();
        for (unsigned i = 0; i < n; ++i) {
            sum += vertexes[i].get_x() * vertexes[(i + 1) % n].get_y() -
                   vertexes[i].get_y() * vertexes[(i + 1) % n].get_x();
        }
        cout << "S=" << abs(sum / 2) << endl;
        return abs(sum / 2);
    }
};

// многоугольник
class Polygon : public ClosedPolyline {
public:

    Polygon(): ClosedPolyline(){
        cout << "Polygon constructor"<< endl;
    };

    Polygon(Point points[], unsigned size) : ClosedPolyline(points, size) {
        cout << "Polygon constructor with points"<< endl;
    };
};

class Triangle : public Polygon {

public:

    Triangle(Point points[3]) : Polygon(points, 3) {
        cout << "Triangle constructor"<< endl;
    }

};

// трапеция
class Trapezoid : public Polygon {

public:

    Trapezoid(Point points[4]) : Polygon(points, 4) {
        add_vertex(points[0].get_x(), points[0].get_y());
        add_vertex(points[1].get_x(), points[1].get_y());
        add_vertex(points[2].get_x(), points[2].get_y());
        add_vertex(points[3].get_x(), points[3].get_y());
    };

};

class RegularPolygon : public  Polygon {
public:
    RegularPolygon() : Polygon(){
        cout << "RegularPolygon constructor"<< endl;
    };
};


int main() {

    ClosedPolyline poly1;

    poly1.add_vertex(0, 2);
    poly1.add_vertex(13, 42);
    poly1.add_vertex(43, 16);


    int poly_size = poly1.get_num_vertexes();
    cout << "poly1 size:" << poly_size << endl;
    for (int n = 0; n < poly_size; n++) {

        Point point = poly1.get_vertex(n);

        cout << "point " << n + 1 << endl;
        cout << "x:" << point.get_x() << endl;
        cout << "y:" << point.get_y() << endl;
    }

    poly1.area();


    cout << "============================="<< endl;

    Point triangle_vertexes[] = {Point(0, 2), Point(13, 42), Point(43, 16)};
    Triangle triangle1(triangle_vertexes);

    cout << endl << "triangle" << endl;
    for (int n = 0; n < 3; n++) {

        Point point = triangle1.get_vertex(n);

        cout << "point " << n + 1 << endl;
        cout << "x:" << point.get_x() << endl;
        cout << "y:" << point.get_y() << endl;
    }

    triangle1.perimeter();
    triangle1.area();

    cout << "============================="<< endl;

    Point trapezoid_vertexes[]={Point(0, 2), Point(13, 42), Point(43, 16), Point(43, 16)};
    Trapezoid trapezoid1(trapezoid_vertexes);

    cout << endl << "trapezoid" << endl;

    for (int n = 0; n < 4; n++) {

        Point point = trapezoid1.get_vertex(n);

        cout << "point " << n + 1 << endl;
        cout << "x:" << point.get_x() << endl;
        cout << "y:" << point.get_y() << endl;
    }

    cout << "perimeter:" << trapezoid1.perimeter() << endl;

    cout << "============================="<< endl;

    Point point1 = Point(23,5);
    point1.print();
    Point point2 = Point(43,48);
    point2.print();
    // оператор присваивания
    Point point3 = point1;
    point3.print();


    return 0;
}