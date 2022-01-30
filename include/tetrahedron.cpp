//
// Created by Dimitar Banev on 09/05/2021.
//

#include "tetrahedron.hpp"

Tetrahedron::Tetrahedron() {
    this->pointA = Point(0, 0, 0);
    this->pointB = Point(0, 0, 0);
    this->pointC = Point(0, 0, 0);
    this->pointD = Point(0, 0, 0);
}

bool Tetrahedron::validatePoints() {
    if (this->pointA == this->pointB || this->pointA == this->pointC || this->pointA == this-> pointD ||
    this->pointB == this->pointC || this->pointB == this->pointD || this->pointC == this->pointD){
        throw EqualPointException();
    }
    return true;
}

Tetrahedron::Tetrahedron(const Point &pointA, const Point &pointB, const Point &pointC, const Point &pointD) {
    this->pointA = pointA;
    this->pointB = pointB;
    this->pointC = pointC;
    this->pointD = pointD;
    try {
        this->validatePoints();
    } catch (EqualPointException & e) {
        std::cout << e.what() << std::endl;
    }
}

Tetrahedron::Tetrahedron(const Tetrahedron &tetrahedron) : Triangle(tetrahedron) {
    this->pointA = tetrahedron.pointA;
    this->pointB = tetrahedron.pointB;
    this->pointC = tetrahedron.pointC;
    this->pointD = tetrahedron.pointD;
}

Tetrahedron &Tetrahedron::operator=(const Tetrahedron &tetrahedron) {
    this->pointA = tetrahedron.pointA;
    this->pointB = tetrahedron.pointB;
    this->pointC = tetrahedron.pointC;
    this->pointD = tetrahedron.pointD;
    return *this;
}

bool Tetrahedron::regularTetrahedron() {
    double a, b, c, d, e, f;
    a = ab.segmentLength();
    b = ac.segmentLength();
    c = ad.segmentLength();
    d = bc.segmentLength();
    e = bd.segmentLength();
    f = cd.segmentLength();
    if((a == b) && (a == c) && (a == d) && (a == e) && (a == f)){
        return true;
    } else {
        return false;
    }
}

void Tetrahedron::setABCD() {
    this->ab = Segment(this->pointA, this->pointB);
    this->ac = Segment(this->pointA, this->pointC);
    this->ad = Segment(this->pointA, this->pointD);
    this->bc = Segment(this->pointB, this->pointC);
    this->bd = Segment(this->pointB, this->pointD);
    this->cd = Segment(this->pointC, this->pointD);
}

double Tetrahedron::surfaceTetrahedron() {
    Triangle triangle_1 = Triangle(this->pointA, this->pointB, this->pointC);
    Triangle triangle_2 = Triangle(this->pointA, this->pointB, this->pointD);
    Triangle triangle_3 = Triangle (this->pointA, this->pointC, this->pointD);
    Triangle triangle_4 = Triangle (this->pointB, this->pointC, this->pointD);
    double result = triangle_1.triangleArea() + triangle_2.triangleArea() + triangle_3.triangleArea() + triangle_4.triangleArea();
    return result;
}

double Tetrahedron::volumeTetrahedron() {
    Vector a(this->pointA, this->pointB);
    Vector b(this->pointA, this->pointC);
    Vector c(this->pointA, this->pointD);
    return a(b, c) / 6;
}

bool Tetrahedron::operator<(const Point &point) const {
    Point p1 = this->pointA;
    Point p2 = this->pointB;
    Point p3 = this->pointC;
    Point p4 = this->pointD;

    double min_x = std::min(std::min(p1.getX(), p2.getX()), std::min(p3.getX(), p4.getX()));
    double max_x = std::max(std::max(p1.getX(), p2.getX()), std::max(p3.getX(), p4.getX()));

    double min_y = std::min(std::min(p1.getY(), p2.getY()), std::min(p3.getY(), p4.getY()));
    double max_y = std::max(std::max(p1.getY(), p2.getY()), std::max(p3.getY(), p4.getY()));

    double min_z = std::min(std::min(p1.getZ(), p2.getZ()), std::min(p3.getZ(), p4.getZ()));
    double max_z = std::max(std::max(p1.getZ(), p2.getZ()), std::max(p3.getZ(), p4.getZ()));

    double a = point.getX();
    double b = point.getY();
    double c = point.getZ();

    if(a > min_x && a < max_x && b > min_y && b < max_y && c > min_z && c < max_z){
        return true;
    } return false;
}

bool Tetrahedron::operator>(const Point &point) const {
    Point p1 = this->pointA;
    Point p2 = this->pointB;
    Point p3 = this->pointC;
    Point p4 = this->pointD;

    double min_x = std::min(std::min(p1.getX(), p2.getX()), std::min(p3.getX(), p4.getX()));
    double max_x = std::max(std::max(p1.getX(), p2.getX()), std::max(p3.getX(), p4.getX()));

    double min_y = std::min(std::min(p1.getY(), p2.getY()), std::min(p3.getY(), p4.getY()));
    double max_y = std::max(std::max(p1.getY(), p2.getY()), std::max(p3.getY(), p4.getY()));

    double min_z = std::min(std::min(p1.getZ(), p2.getZ()), std::min(p3.getZ(), p4.getZ()));
    double max_z = std::max(std::max(p1.getZ(), p2.getZ()), std::max(p3.getZ(), p4.getZ()));

    double a = point.getX();
    double b = point.getY();
    double c = point.getZ();

    if((a < min_x || a > max_x) && (b < min_y || b > max_y) && (c < min_z || c > max_z)){
        return true;
    } return false;
}

bool Tetrahedron::operator==(const Point &point) const {
    Triangle triangle_1 = Triangle(this->pointA, this->pointB, this->pointD);
    Triangle triangle_2 = Triangle(this->pointA, this->pointC, this->pointD);
    Triangle triangle_3 = Triangle(this->pointB, this->pointC, this->pointD);

    if(triangle_1 == point || triangle_2 == point || triangle_3 == point){
        return true;
    } return false;
}


bool Tetrahedron::orthogonalTetrahedron() {
    Line lineAD = Line(pointA, pointD);
    Line lineBC = Line(pointB, pointC);

    Line lineAC = Line(pointA, pointC);
    Line lineBD = Line(pointB, pointD);

    Line lineAB = Line(pointA, pointB);
    Line lineCD = Line(pointC, pointD);

    if((lineAD | lineBC) && (lineAC | lineBD) && (lineAB | lineCD)){
        return true;
    } return false;
}

void Tetrahedron::printFunctions() {
    int function_choice;
    Point point;
    std::cout << "Functions:" << std::endl;
    std::cout << "1 - Check if the tetrahedron is regular" << std::endl;
    std::cout << "2 - Check if the tetrahedron is orthogonal" << std::endl;
    std::cout << "3 - Find the surface of the tetrahedron" << std::endl;
    std::cout << "4 - Find the volume of the tetrahedron" << std::endl;
    std::cout << "5 - Check if a point lies inside of the tetrahedron's plane (<)" << std::endl;
    std::cout << "6 - Check if a point lies outside of the tetrahedron's plane (>)" << std::endl;
    std::cout << "7 - Check if a point lies on any of the tetrahedron's sides (==)" << std::endl;
    std::cout << "0 - Quit" << std::endl;
    std::cout << "Please select a function:";
    std::cin >> function_choice;

    while(function_choice > 7){
        std::cout << "Please enter a valid function number:";
        std::cin >> function_choice;
    }

    switch(function_choice) {
        case 0:
            exit(0);
        case 1:
            if(this->regularTetrahedron()){
                std::cout << "The tetrahedron is regular!" << std::endl;
            } else {
                std::cout << "The tetrahedron is NOT regular!" << std::endl;
            }
            selectNewFunction(this);
            break;
        case 2:
            if(this->orthogonalTetrahedron()){
                std::cout << "The tetrahedrons is orthogonal!" << std::endl;
            } else {
                std::cout << "The tetrahedron is NOT orthogonal!" << std::endl;
            }
            selectNewFunction(this);
            break;
        case 3:
            std::cout << "The surface of the tetrahedron is " << this->surfaceTetrahedron() << std::endl;
            selectNewFunction(this);
            break;
        case 4:
            std::cout << "The tetrahedron's volume is " << this->volumeTetrahedron() << std::endl;
            selectNewFunction(this);
            break;
        case 5:
            std::cin >> point;
            if(*this < point){
                std::cout << "The point " << point << " lies inside of the tetrahedron's sides!" << std::endl;
                selectNewFunction(this);
            } else {
                std::cout << "The point " << point << " does NOT lies inside of the tetrahedron's sides!" << std::endl;
                selectNewFunction(this);
            }
            break;
        case 6:
            std::cin >> point;
            if(*this > point){
                std::cout << "The point " << point << " lies outside of the tetrahedron's sides!" << std::endl;
                selectNewFunction(this);
            } else {
                std::cout << "The point " << point << " does NOT lies outside of the tetrahedron's sides!" << std::endl;
                selectNewFunction(this);
            }
            break;
        case 7:
            std::cin >> point;
            if(*this == point){
                std::cout << "The point " << point << " lies on a side of the tetrahedron's plane!" << std::endl;
                selectNewFunction(this);
            } else {
                std::cout << "The point " << point << " does NOT lies on a side of the tetrahedron's plane!" << std::endl;
                selectNewFunction(this);
            }
            break;
        default:
            std::cout << "Created by Dimitar Banev - github.com/devastion" << std::endl;
            printFunctions();
            break;
    }
}


Tetrahedron::~Tetrahedron() = default;
