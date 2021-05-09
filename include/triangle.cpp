//
// Created by Dimitar Banev on 07/05/2021.
//

#include "triangle.hpp"

Triangle::Triangle() : Point() {
    pointA = Point(0, 0, 0);
    pointB = Point(0, 0, 0);
    pointC = Point(0, 0, 0);
    ab = 0;
    bc = 0;
    ac = 0;
}

Triangle::Triangle(const Triangle &triangle) : Point(triangle) {
    pointA = triangle.pointA;
    pointB = triangle.pointB;
    pointC = triangle.pointC;
}

bool Triangle::arePointsEqual() const {
    try{
        if(pointA == pointB){
            throw EqualPointException();
        }

        if(pointB == pointC){
            throw EqualPointException();
        }

        if(pointA == pointC){
            throw EqualPointException();
        }
    } catch (EqualPointException & e) {
        std::cout << e.what() << std::endl;
    }
    return true;
}

Triangle::Triangle(const Point &pointA, const Point &pointB, const Point &pointC) {
    this->pointA = pointA;
    this->pointB = pointB;
    this->pointC = pointC;
}

double Triangle::getAB() const {
    return ab;
}
double Triangle::getBC() const {
    return bc;
}
double Triangle::getAC() const {
    return ac;
}
Point Triangle::getPointA() const {
    return this->pointA;
}
Point Triangle::getPointB() const {
    return this->pointB;
}
Point Triangle::getPointC() const {
    return this->pointC;
}

void Triangle::setABC() {
    this->ab = sqrt((this->pointB.getX() - this->pointA.getX()) * (this->pointB.getX() - this->pointA.getX()) + ((this->pointB.getY() - this->pointA.getY()) * (this->pointB.getY() - this->pointA.getY())) + ((this->pointB.getZ() - this->pointA.getZ()) * (this->pointB.getZ() - this->pointA.getZ())));
    this->bc = sqrt((this->pointC.getX() - this->pointB.getX()) * (this->pointC.getX() - this->pointB.getX()) + ((this->pointC.getY() - this->pointB.getY()) * (this->pointC.getY() - this->pointB.getY())) + ((this->pointC.getZ() - this->pointB.getZ()) * (this->pointC.getZ() - this->pointB.getZ())));
    this->ac = sqrt((this->pointC.getX() - this->pointA.getX()) * (this->pointC.getX() - this->pointA.getX()) + ((this->pointC.getY() - this->pointA.getY()) * (this->pointC.getY() - this->pointA.getY())) + ((this->pointC.getZ() - this->pointA.getZ()) * (this->pointC.getZ() - this->pointA.getZ())));
}

void Triangle::triangleKind() const {
    if (this->ab ==this->bc == this->ac)
    {
        std::cout << "Triangle is equilateral" << std::endl;
    }
    if (this->ab == this->bc || this->ab == this->ac || this->bc == this->ac)
    {
        std::cout << "Triangle is Isosceles" << std::endl;
    }
    if (this->ab * this->ab + this->bc * this->bc == this->ac * this->ac || this->bc * this->bc + this->ac * this->ac == this->ab * this->ab || this->ab * this->ab + this->ac * this->ac == this->bc * this->bc)
    {
        std::cout << "Triangle is right angled!" << std::endl;
    }
    if (this->ac * this->ac < this->ab * this->ab + this->bc * this->bc || this->ab * this->ab < this->ac * this->ac + this->bc * this->bc || this->bc * this->bc < this->ac * this->ac + this->ab * this->ab)
    {
        std::cout << "Triangle is acute!" << std::endl;
    }

    if (this->ac * this->ac > this->ab * this->ab + this->bc * this->bc || this->ab * this->ab > this->ac * this->ac + this->bc * this->bc || this->bc * this->bc > this->ac * this->ac + this->ab * this->ab)
    {
        std::cout << "Triangle is obtuse!" << std::endl;
    }
}

double Triangle::trianglePerimeter() const {
    double sum = this->getAB() + this->getBC() + this->getAC();
    return sum;
}

double Triangle::triangleArea() const {
    double perimeter = this->trianglePerimeter();
    return sqrt(perimeter * ((perimeter - this->ac ) * (perimeter -this->bc ) * (perimeter - this->ac)));
}

Point Triangle::triangleIncenter() const {
    double x = (this->pointA.getX() + this->pointB.getX() + this->pointC.getX()) / 3;
    double y = (this->pointA.getY() + this->pointB.getY() + this->pointC.getY()) / 3;
    double z = (this->pointA.getZ() + this->pointB.getZ() + this->pointC.getZ()) / 3;
    return Point(x, y, z);
}

bool Triangle::operator<(const Point &point) const {
    double ax = this->pointA.getX(); double ay = this->pointB.getY();
    double bx = this->pointB.getX(); double by = this->pointB.getY();
    double cx = this->pointC.getX(); double cy = this->pointC.getY();
    double px = point.getX(); double py = this->getY();
    double a, b, c;
    a = (by - cy) * (px - cx) + (cx - bx) * (py - cy) / (by - cy) * (ax - cx) + (cx - bx) * (ay - cy);
    b = (cy - ay) * (px - cx) + (ac - cx) * (py - cy) / (by - cy) * (ac - cx) + (cx - bx) * (ay - cy);
    c = 1.0 - a - b;
    if((a > 0) && (b > 0) && (c > 0)){
        return true;
    }else {
        return false;
    }
}

bool Triangle::operator>(const Point &point) const {
    double ax = this->pointA.getX(); double ay = this->pointB.getY();
    double bx = this->pointB.getX(); double by = this->pointB.getY();
    double cx = this->pointC.getX(); double cy = this->pointC.getY();
    double px = point.getX(); double py = this->getY();
    double a, b, c;
    a = (by - cy) * (px - cx) + (cx - bx) * (py - cy) / (by - cy) * (ax - cx) + (cx - bx) * (ay - cy);
    b = (cy - ay) * (px - cx) + (ac - cx) * (py - cy) / (by - cy) * (ac - cx) + (cx - bx) * (ay - cy);
    c = 1.0 - a - b;
    if((a > 0) && (b > 0) && (c > 0)){
        return false;
    }else {
        return true;
    }
}

bool Triangle::operator==(const Point &point) const {
    double ax = this->pointA.getX(); double ay = this->pointB.getY();
    double bx = this->pointB.getX(); double by = this->pointB.getY();
    double cx = this->pointC.getX(); double cy = this->pointC.getY();
    double px = point.getX(); double py = this->getY();
    double a, b, c;
    a = (by - cy) * (px - cx) + (cx - bx) * (py - cy) / (by - cy) * (ax - cx) + (cx - bx) * (ay - cy);
    b = (cy - ay) * (px - cx) + (ac - cx) * (py - cy) / (by - cy) * (ac - cx) + (cx - bx) * (ay - cy);
    c = 1.0 - a - b;
    if((a == 0) && (b == 0) && (c == 0)){
        return true;
    }else {
        return false;
    }
}

Triangle &Triangle::operator=(const Triangle &triangle) {
    if(this != &triangle) {
        this->pointA = triangle.pointA;
        this->pointB = triangle.pointB;
        this->pointC = triangle.pointC;
    }
    return *this;
}

void Triangle::printFunctions() {
    int function_choice;
    Point point;
    std::cout << "Functions:" << std::endl;
    std::cout << "1 - Find what is the kind of the triangle" << std::endl;
    std::cout << "2 - Find the area of the triangle" << std::endl;
    std::cout << "3 - Find the perimeter of the triangle" << std::endl;
    std::cout << "4 - Find the incenter of the triangle" << std::endl;
    std::cout << "5 - Check if a point lies inside of the triangle's plane (<)" << std::endl;
    std::cout << "6 - Check if a point lies outside of the triangle's plane (>)" << std::endl;
    std::cout << "7 - Check if a point lies on any of the triangle's sides (==)" << std::endl;
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
            this->triangleKind();
            selectNewFunction(this);
            break;
        case 2:
            std::cout << "The triangle area is " << this->triangleArea() << std::endl;
            selectNewFunction(this);
            break;
        case 3:
            std::cout << "The perimeter of the triangle is " << this->trianglePerimeter() << std::endl;
            selectNewFunction(this);
            break;
        case 4:
            std::cout << "The triangle's incenter is " << this->triangleIncenter() << std::endl;
            selectNewFunction(this);
            break;
        case 5:
            std::cin >> point;
            if(*this < point){
                std::cout << "The point " << point << " lies inside of the triangle's plane!" << std::endl;
                selectNewFunction(this);
            } else {
                std::cout << "The point " << point << " does NOT lies inside of the triangle's plane!" << std::endl;
                selectNewFunction(this);
            }
            break;
        case 6:
            std::cin >> point;
            if(*this > point){
                std::cout << "The point " << point << " lies outside of the triangle's plane!" << std::endl;
                selectNewFunction(this);
            } else {
                std::cout << "The point " << point << " does NOT lies outside of the triangle's plane!" << std::endl;
                selectNewFunction(this);
            }
            break;
        case 7:
            std::cin >> point;
            if(*this == point){
                std::cout << "The point " << point << " lies on a side of the triangle's plane!" << std::endl;
                selectNewFunction(this);
            } else {
                std::cout << "The point " << point << " does NOT lies on a side of the triangle's plane!" << std::endl;
                selectNewFunction(this);
            }
            break;
        default:
            std::cout << "Created by Dimitar Banev - github.com/devastion" << std::endl;
            printFunctions();
            break;
    }
}

Triangle::~Triangle() = default;