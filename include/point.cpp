//
// Created by Dimitar Banev on 07/05/2021.
//

#include "point.hpp"

Point::Point() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Point::Point(double a, double b, double c) {
    this->x = a;
    this->y = b;
    this->z = c;
}

Point::Point(const Point &point) {
    this->x = point.x;
    this->y = point.y;
    this->z = point.z;
}

Point &Point::operator=(const Point &point) {
    this->x = point.x;
    this->y = point.y;
    this->z = point.z;
    return *this;
}

double Point::getX() const {
    return this->x;
}
double Point::getY() const {
    return this->y;
}
double Point::getZ() const {
    return this->z;
}

void Point::setX(double n) {
    this->x = n;
}
void Point::setY(double n) {
    this->y = n;
}
void Point::setZ(double n) {
    this->z = n;
}

bool Point::operator==(const Point &point) const {
    if(this->x == point.x && this->y == point.y && this->z == point.z){
        return true;
    } else {
        return false;
    }
}

void Point::printFunctions() {
    int function_choice;
    bool result;
    Point second_point;
    std::cout << "Functions:" << std::endl;
    std::cout << "1 - Check if two points are equal" << std::endl;
    std::cout << "0 - Quit" << std::endl;
    std::cout << "Please select a function:";
    std::cin >> function_choice;

    while(function_choice > 1 || function_choice < 0){
        std::cout << "Please enter a valid function number:";
        std::cin >> function_choice;
    }

    switch(function_choice){
        case 0:
            exit(0);
        case 1:
            std::cout << "Please enter values for the second point:" << std::endl;
            std::cin >> second_point;
            result = second_point == *this;
            std::cout << *this << " == " << second_point << " ?" << std::endl;
            if(result){
                std::cout << "Both points are equal!" << std::endl;
            } else {
                std::cout << "Points are NOT equal!" << std::endl;
            }
            selectNewFunction(this);
            break;
        default:
            std::cout << "Created by Dimitar Banev - github.com/devastion";
            break;
    }
}

Point::~Point() = default;
