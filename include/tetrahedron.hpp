//
// Created by Dimitar Banev on 09/05/2021.
//

#ifndef VECTORS_CALCULATOR_TETRAHEDRON_HPP
#define VECTORS_CALCULATOR_TETRAHEDRON_HPP

#include "triangle.hpp"
#include "equalpointexception.hpp"
#include "segment.hpp"
#include "vector.hpp"
#include <algorithm>

class Tetrahedron : public Triangle{
private:
    Point pointA, pointB, pointC, pointD;
    Segment ab, ac, ad, bc, bd, cd;

public:
    Tetrahedron();
    ~Tetrahedron();
    Tetrahedron(const Point& pointA, const Point& pointB, const Point& pointC, const Point& pointD);
    Tetrahedron(const Tetrahedron& tetrahedron);
    Tetrahedron& operator=(const Tetrahedron& tetrahedron);

    bool validatePoints();
    bool regularTetrahedron();
    void setABCD();
    double surfaceTetrahedron();
    double volumeTetrahedron();
    bool orthogonalTetrahedron();

    bool operator<(const Point& point) const override;
    bool operator>(const Point& point) const override;
    bool operator==(const Point& point) const override;

    inline std::ostream& output(std::ostream& out) const override;
    inline std::istream& input(std::istream& in) override;

    void printFunctions() override;
};

std::ostream &Tetrahedron::output(std::ostream &out) const{
    return out << "Triangle \n" << "First Point: " << Tetrahedron::pointA << "\n Second Point: " << Tetrahedron::pointB << "\n Third Point: " << Tetrahedron::pointC << "\n Forth Point: " << Tetrahedron::pointD;
}

std::istream &Tetrahedron::input(std::istream &in) {
    std::cout << "Please enter values for the first point:" << std::endl;
    in >> this->pointA;
    std::cout << "Please enter values for the second point:" << std::endl;
    in >> this->pointB;
    std::cout << "Please enter values for the third point:" << std::endl;
    in >> this->pointC;
    std::cout << "Please enter values for the forth point:" << std::endl;
    in >> this->pointD;
    return in;
}

inline std::ostream &operator<<(std::ostream &out, const Tetrahedron& tetrahedron) {
    return tetrahedron.output(out);
}

inline std::istream &operator>>(std::istream &in, Tetrahedron& tetrahedron){
    return tetrahedron.input(in);
}

#endif //VECTORS_CALCULATOR_TETRAHEDRON_HPP
