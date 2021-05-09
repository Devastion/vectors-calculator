//
// Created by Dimitar Banev on 07/05/2021.
//

#ifndef VECTORS_CALCULATOR_SEGMENT_HPP
#define VECTORS_CALCULATOR_SEGMENT_HPP

#include "line.hpp"

class Segment : public Line{
private:
    Point firstPoint;
    Point secondPoint;

public:
    Segment();
    ~Segment();
    Segment(const Point& firstPoint, const Vector& vector);
    Segment(const Point& firstPoint, const Point& secondPoint);

    double segmentLength() const;
    Point segmentMidPoint() const;

    bool operator==(const Point& thirdPoint);

    inline std::ostream& output(std::ostream& out) const override;
    inline std::istream& input(std::istream& in) override;

    void printFunctions() override;
};

std::ostream &Segment::output(std::ostream &out) const{
    return out << "Segment \n" << "First Point: " << Segment::firstPoint << "\n Second Point: " << Segment::secondPoint;
}

std::istream &Segment::input(std::istream &in) {
    std::cout << "Please enter value for the first point:" << std::endl;
    in >> this->firstPoint;
    std::cout << "Please enter value for the second point:" << std::endl;
    in >> this->secondPoint;
    return in;
}

inline std::ostream &operator<<(std::ostream &out, const Segment& segment) {
    return segment.output(out);
}

inline std::istream &operator>>(std::istream &in, Segment& segment){
    return segment.input(in);
}

#endif //VECTORS_CALCULATOR_SEGMENT_HPP
