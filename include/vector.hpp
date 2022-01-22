//
// Created by Dimitar Banev on 07/05/2021.
//

#ifndef VECTORS_CALCULATOR_VECTOR_HPP
#define VECTORS_CALCULATOR_VECTOR_HPP

#include "point.hpp"
#include "vectorlengthexception.hpp"

class Vector : public Point{
public:
    Vector();
    ~Vector();
    Vector(double a, double b, double c);
    Vector(const Point& point_1, const Point& point_2);

    double vectorLength() const;
    Vector vectorDirection() const;
    bool vectorZero() const;
    bool vectorParallel(const Vector& vector) const;
    bool vectorPerpendicular(const Vector& vector) const;

    Vector operator+(const Vector& vector) const;
    Vector operator-(const Vector& vector) const;
    Vector operator*(double r) const;
    double operator*(const Vector& vector) const;
    Vector operator^(const Vector& vector) const;
    double operator()(const Vector& vector_1, const Vector& vector_2) const;

    inline std::ostream& output(std::ostream& out) const override;
    inline std::istream& input(std::istream& in) override;

    void printFunctions() override;
};

std::ostream &Vector::output(std::ostream &out) const{
    return out << "Vector(" << getX() << ", " << getY() << ", " << getZ() <<")";
}

std::istream &Vector::input(std::istream &in) {
    double a, b, c;
    std::cout << "x:"; in >> a; this->setX(a);
    std::cout << "y:"; in >> b; this->setY(b);
    std::cout << "z:"; in >> c; this->setZ(c);
    return in;
}

inline std::ostream &operator<<(std::ostream &out, const Vector& vector) {
    return vector.output(out);
}

inline std::istream &operator>>(std::istream &in, Vector& vector){
    return vector.input(in);
}

#endif //VECTORS_CALCULATOR_VECTOR_HPP
