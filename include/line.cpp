//
// Created by Dimitar Banev on 07/05/2021.
//

#include "line.hpp"

Line::Line() {
    firstPoint = Point(0, 0, 0);
    secondPoint = Point(0, 0, 0);
    vectorConstructor = Vector(0, 0, 0);
}

Line::Line(const Point &point, const Vector &vector) {
    double a1 = point.getX(); double a2 = vector.getX();
    double b1 = point.getY(); double b2 = vector.getY();
    double c1 = point.getZ(); double c2 = vector.getZ();
    this->firstPoint = Point(a1, b1, c1);
    this->secondPoint = Point(a2, b2, c2);
}

Line::Line(const Point &point_1, const Point &point_2){
    Vector vector(point_1, point_2);
    double a1 = point_1.getX(); double a2 = vector.getX();
    double b1 = point_1.getY(); double b2 = vector.getY();
    double c1 = point_1.getZ(); double c2 = vector.getZ();
    this->firstPoint = Point(a1, b1, c1);
    this->secondPoint = Point(a2, b2, c2);
}

Line::Line(const Line &line)  : Vector(line) {
    this->firstPoint = line.firstPoint;
    this->secondPoint = line.secondPoint;
}

Point Line::getFirstPoint() const {
    return this->firstPoint;
}

Point Line::getSecondPoint() const {
    return this->secondPoint;
}


Vector Line::lineDirection() const {
    Vector vector;
    Vector vector_1(this->getFirstPoint().getX(), this->getFirstPoint().getY(), this->getFirstPoint().getZ());
    Vector vector_2(this->getSecondPoint().getX(), this->getSecondPoint().getY(), this->getSecondPoint().getZ());
    try {
        if(vector_1.vectorZero() || vector_2.vectorZero()){
            throw VectorLengthException();
        }
        vector.setX(vector_1.getY() * vector_2.getZ() - vector_1.getZ() * vector_2.getY());
        vector.setY(vector_1.getZ() * vector_2.getX() - vector_1.getX() * vector_2.getZ());
        vector.setZ(vector_1.getX() * vector_2.getY() - vector_1.getY() * vector_2.getX());
        return vector;
    } catch (VectorLengthException & e){
        std::cout << std::endl << e.what() << std::endl;
        return vector;
    }
}

Vector Line::lineNormal() const {
    Vector vector_1(this->getFirstPoint(), this->getSecondPoint());
    Vector vector_2(1, 0, 0);
    double a = vector_1.getY() * vector_2.getZ() - vector_1.getZ() * vector_2.getY();
    double b = vector_1.getZ() * vector_2.getX() - vector_1.getX() * vector_2.getZ();
    double c = vector_1.getX() * vector_2.getY() - vector_1.getY() * vector_2.getX();
    return Vector(a, b, c);
}

double Line::lineAngle(const Line &line) const {
    Vector vector_1(this->getFirstPoint(), this->getSecondPoint());
    vector_1.vectorDirection();
    Vector vector_2(line.getFirstPoint(), line.getSecondPoint());
    vector_2.vectorDirection();
    return std::acos((vector_1 * vector_2) / (vector_1.vectorLength() * vector_2.vectorLength()));
}

bool Line::operator+(const Point &point) const {
    double x1 = this->getFirstPoint().getX(); double x2 = this->getSecondPoint().getX();
    double y1 = this->getFirstPoint().getY(); double y2 = this->getSecondPoint().getY();
    double z1 = this->getFirstPoint().getZ(); double z2 = this->getSecondPoint().getZ();
    double x = point.getX(); double y = point.getY(); double z = point.getZ();
    double a = (x - x1) / (x2 - x1); double b = (y - y1) / (y2 - y1); double c = (z - z1) / (z2 - z1);
    double tmp = (a - b - c);
    if(tmp<0.2 && tmp>-0.2){
        return true;
    } else {
        return false;
    }
}

bool Line::operator||(const Line &line) const {
    Vector vector_1(this->getFirstPoint(), this->getSecondPoint());
    Vector vector_2(line.getFirstPoint(), line.getSecondPoint());
    if(vector_1.vectorParallel(vector_2)){
        return true;
    } else {
        return false;
    }
}

bool Line::operator==(const Line &line) const {
    Vector vector_1(this->getFirstPoint(), this->getSecondPoint());
    Vector vector_2(line.getFirstPoint(), line.getSecondPoint());
    double a1 = vector_1.getX(); double a2 = vector_2.getX();
    double b1 = vector_1.getY(); double b2 = vector_2.getY();
    double c1 = vector_1.getZ(); double c2 = vector_2.getZ();
    if((a1 / a2 == b1 / b2) && (a1 / a2 == c1 / c2) && (b1 / b2 == c1 / c2)){
        return true;
    } else {
        return false;
    }
}

bool Line::operator&&(const Line &line) const {
    Vector vector_1(this->getFirstPoint(), this->getSecondPoint());
    Vector vector_2(line.getFirstPoint(), line.getSecondPoint());
    double x1 = vector_1.getX(); double x2 = vector_2.getX();
    double y1 = vector_1.getY(); double y2 = vector_2.getY();
    double z1 = vector_1.getZ(); double z2 = vector_2.getZ();
    if((x1 == x2) || (y1 == y2) || (z1 == z2)){
        return true;
    } else {
        return false;
    }
}

bool Line::operator!=(const Line &line) const {
    if(!(*this || line)){
        return true;
    } else {
        return false;
    }
}

bool Line::operator|(const Line &line) const {
    Vector vector_1(this->getFirstPoint(), this->getSecondPoint());
    Vector vector_2(line.getFirstPoint(), line.getSecondPoint());
    double x1 = vector_1.getX(); double x2 = vector_2.getX();
    double y1 = vector_1.getY(); double y2 = vector_2.getY();
    double z1 = vector_1.getZ(); double z2 = vector_2.getZ();
    if ((x1 * x2 + y1 * y2 + z1 * z2 < 0.02) && (x1 * x2 + y1 * y2 + z1 * z2 > -0.02)){
        return true;
    } else {
        return false;
    }
}

void Line::printFunctions() {
    int function_choice;
    Line line;
    Point point;

    std::cout << "Functions:" << std::endl;
    std::cout << "1 - Line direction" << std::endl;
    std::cout << "2 - Normal vector of the line" << std::endl;
    std::cout << "3 - Angle between two lines" << std::endl;
    std::cout << "4 - Check if a point lies on the line (+)" << std::endl;
    std::cout << "5 - Check if a line is parallel (||)" << std::endl;
    std::cout << "6 - Check if a line is the same (==)" << std::endl;
    std::cout << "7 - Check if a line intersects (&&)" << std::endl;
    std::cout << "8 - Check if a line crosses (!=)" << std::endl;
    std::cout << "9 - Check if a line is perpendicular (|)" << std::endl;
    std::cout << "-1 - Edit the main line" << std::endl;
    std::cout << "0 - Quit" << std::endl;
    std::cout << "Please select a function:";
    std::cin >> function_choice;

    while(function_choice > 9){
        std::cout << "Please enter a valid function number:";
        std::cin >> function_choice;
    }

    switch(function_choice){
        case 0:
            exit(0);
        case 1:
            std::cout << "Line direction is " << this->lineDirection() << std::endl;
            selectNewFunction(this);
            break;
        case 2:
            std::cout << "The normal vector of the line is " << this->lineNormal() << std::endl;
            selectNewFunction(this);
            break;
        case 3:
            std::cin >> line;
            std::cout << "The angle between both lines is " << this->lineAngle(line) << std::endl;
            selectNewFunction(this);
            break;
        case 4:
            std::cout << "Enter values for the point:" << std::endl;
            std::cin >> point;
            if(*this + (point)){
                std::cout << "The point " << point << " lies on the line!" << std::endl;
                selectNewFunction(this);
            } else {
                std::cout << "The point " << point << " doesn't lie on the line!" << std::endl;
                selectNewFunction(this);
            }
            break;
        case 5:
            std::cin >> line;
            if(*this || line){
                std::cout << "The line is parallel!" << std::endl;
                selectNewFunction(this);
            } else {
                std::cout << "The line is NOT parallel!" << std::endl;
                selectNewFunction(this);
            }
            break;
        case 6:
            std::cin >> line;
            if(*this == line){
                std::cout << "The line is the same!" << std::endl;
                selectNewFunction(this);
            } else {
                std::cout << "The line is NOT the same!" << std::endl;
                selectNewFunction(this);
            }
            break;
        case 7:
            std::cin >> line;
            if(*this && line){
                std::cout << "The line intersects!" << std::endl;
                selectNewFunction(this);
            } else {
                std::cout << "The line do NOT intersect!" << std::endl;
                selectNewFunction(this);
            }
            break;
        case 8:
            std::cin >> line;
            if(*this != line){
                std::cout << "The line is crossed with the main line!" << std::endl;
                selectNewFunction(this);
            } else {
                std::cout << "The line doesn't cross the main line!" << std::endl;
                selectNewFunction(this);
            }
        case 9:
            std::cin >> line;
            if(*this | line){
                std::cout << "The line is perpendicular" << std::endl;
                selectNewFunction(this);
            } else {
                std::cout << "The line is NOT perpendicular" << std::endl;
                selectNewFunction(this);
            }
            break;
        case -1:
            std::cin >> *this;
            printFunctions();
            break;
        default:
            std::cout << "Created by Dimitar Banev - github.com/devastion" << std::endl;
            printFunctions();
            break;
    }
}

Line::~Line() = default;
