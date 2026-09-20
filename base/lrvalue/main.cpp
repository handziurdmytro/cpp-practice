#include <iostream>

struct Point {
    int _x, _y;

    Point(int x, int y) : _x(x), _y(y) {}

    Point& operator+=(const Point& p) {
        _x += p._x;
        _y += p._y;
        return *this;
    }

    int x() const {return _x;}
    int y() const {return _y;}
};

Point operator+(Point p1, const Point& p2) {
    p1 += p2;
    return p1;
} 

std::ostream& operator<<(std::ostream& o, const Point& p) {
    return o << "Point { " << p.x() << ", " << p.y() << " }";
}

void inspect(Point& p) {
    std::cout << "lvalue\n";
}

void inspect(const Point& p) {
    std::cout << "const lvalue\n";
}

void inspect(Point&& p) {
    std::cout << "rvalue\n";
}

int main() {
    Point p1{3, 4};
    Point p2{8, 6};
    Point&& p3{5, 5};

    inspect(p1);
    inspect(p1 + p2);
    inspect(std::move(p1));
    inspect(p3);

    return 0;
}
