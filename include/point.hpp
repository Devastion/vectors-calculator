//
// Created by Dimitar Banev on 07/05/2021.
//

#ifndef VECTORS_CALCULATOR_POINT_HPP
#define VECTORS_CALCULATOR_POINT_HPP

#include "element.hpp"

class Point : public Element{
private:
    double x, y, z;

public:
    Point();
    ~Point();
    Point(double a, double b, double c);
    Point(const Point& point);
    Point& operator=(const Point& point);

    double getX() const;
    double getY() const;
    double getZ() const;

    void setX(double n);
    void setY(double n);
    void setZ(double n);

    virtual bool operator==(const Point& point) const;

    inline std::ostream& output(std::ostream& out) const override;
    inline std::istream& input(std::istream& in) override;

    void printFunctions() override;
};

std::ostream &Point::output(std::ostream &out) const{
    return out << "Point(" << this->getX() << ", " << this->getY() << ", " << this->getZ() <<")";
}
std::istream &Point::input(std::istream &in) {
    std::cout << "x:"; in >> this->x;
    std::cout << "y:"; in >> this->y;
    std::cout << "z:"; in >> this->z;
    return in;
}
inline std::ostream &operator<<(std::ostream &out, const Point& point) {
    return point.output(out);
}
inline std::istream &operator>>(std::istream &in, Point& point){
    return point.input(in);
}

#endif //VECTORS_CALCULATOR_POINT_HPP
