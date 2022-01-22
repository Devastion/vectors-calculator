//
// Created by Dimitar Banev on 07/05/2021.
//

#include "segment.hpp"

Segment::Segment() {
    firstPoint = Point(0, 0, 0);
    secondPoint = Point(0, 0, 0);
}

Segment::Segment(const Point &firstPoint, const Vector &vector) : Line(firstPoint, vector) {
    double x = vector.getX();
    double y = vector.getY();
    double z = vector.getZ();

    secondPoint = Point(firstPoint.getX() + x, firstPoint.getY() + y, firstPoint.getZ() + z);
}

Segment::Segment(const Point &firstPoint, const Point &secondPoint) : Line(firstPoint, secondPoint) {
}

double Segment::segmentLength() const{
    double x = secondPoint.getX() - firstPoint.getX();
    double y = secondPoint.getY() - firstPoint.getY();
    double z = secondPoint.getZ() - firstPoint.getZ();

    Vector vector(x, y, z);
    return vector.vectorLength();
}

Point Segment::segmentMidPoint() const{
    double x = (firstPoint.getX() + secondPoint.getX()) / 2;
    double y = (firstPoint.getY() + secondPoint.getY()) / 2;
    double z = (firstPoint.getZ() + secondPoint.getZ()) / 2;

    return Point(x, y, z);
}

bool Segment::operator==(const Point &thirdPoint) {
    Segment AC(firstPoint, thirdPoint);
    Segment BC(secondPoint, thirdPoint);

    return this->segmentLength() == AC.segmentLength() + BC.segmentLength();
}

void Segment::printFunctions() {
    int function_choice;
    Point point;

    std::cout << "Functions:" << std::endl;
    std::cout << "1 - Find the segment's length" << std::endl;
    std::cout << "2 - Find the middle point of the segment" << std::endl;
    std::cout << "3 - Check if a point lies on the segment (==)" << std::endl;
    std::cout << "0 - Quit" << std::endl;
    std::cout << "Please select a function:";
    std::cin >> function_choice;

    while(function_choice > 3){
        std::cout << "Please enter a valid function number:";
        std::cin >> function_choice;
    }

    switch(function_choice) {
        case 0:
            exit(0);
        case 1:
            std::cout << "The segment length is " << this->segmentLength() << std::endl;
            selectNewFunction(this);
            break;
        case 2:
            std::cout << "The middle point of the segment is " << this->segmentMidPoint() << std::endl;
            selectNewFunction(this);
            break;
        case 3:
            std::cout << "Please enter values for the point:" << std::endl;
            std::cin >> point;
            if(*this == point){
                std::cout << "The point lies on the segment!" << std::endl;
                selectNewFunction(this);
            } else {
                std::cout << "The point does NOT lie on the segment!" << std::endl;
                selectNewFunction(this);
            }
            break;
        default:
            std::cout << "Created by Dimitar Banev - github.com/devastion" << std::endl;
            printFunctions();
            break;
    }
}

Segment::~Segment() = default;
