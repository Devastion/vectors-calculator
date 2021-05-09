//
// Created by Dimitar Banev on 07/05/2021.
//

#ifndef VECTORS_CALCULATOR_TRIANGLE_HPP
#define VECTORS_CALCULATOR_TRIANGLE_HPP

#include "point.hpp"
#include "equalpointexception.hpp"

class Triangle : public Point{
private:
    Point pointA;
    Point pointB;
    Point pointC;
    double ab{}, bc{}, ac{};

public:
    Triangle();
    ~Triangle();
    Triangle(const Triangle& triangle);
    Triangle(const Point& pointA, const Point& pointB, const Point& pointC);
    Triangle& operator=(const Triangle& triangle);

    virtual bool arePointsEqual() const;

    double getAB() const;
    double getBC() const;
    double getAC() const;
    Point getPointA() const;
    Point getPointB() const;
    Point getPointC() const;

    void setABC();

    void triangleKind() const;
    double triangleArea() const;
    double trianglePerimeter() const;
    Point triangleIncenter() const;

    virtual bool operator<(const Point& point) const;

    virtual bool operator>(const Point& point) const;
    bool operator==(const Point& point) const override;

    inline std::ostream& output(std::ostream& out) const override;
    inline std::istream& input(std::istream& in) override;

    void printFunctions() override;
};

std::ostream &Triangle::output(std::ostream &out) const{
    return out << "Triangle \n" << "First Point: " << Triangle::pointA << "\n Second Point: " << Triangle::pointB << "\n Third Point: " << Triangle::pointC;
}

std::istream &Triangle::input(std::istream &in) {
    std::cout << "Please enter values for the first point:" << std::endl;
    in >> this->pointA;
    std::cout << "Please enter values for the second point:" << std::endl;
    in >> this->pointB;
    std::cout << "Please enter values for the third point:" << std::endl;
    in >> this->pointC;
    return in;
}

inline std::ostream &operator<<(std::ostream &out, const Triangle& triangle) {
    return triangle.output(out);
}

inline std::istream &operator>>(std::istream &in, Triangle& triangle){
    return triangle.input(in);
}

#endif //VECTORS_CALCULATOR_TRIANGLE_HPP
