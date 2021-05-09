//
// Created by Dimitar Banev on 07/05/2021.
//

#include "vector.hpp"

Vector::Vector() {
    this->setX(0);
    this->setY(0);
    this->setZ(0);
}

Vector::Vector(double a, double b, double c) : Point(a, b, c) { }

Vector::~Vector() = default;

Vector::Vector(const Point &point_1, const Point &point_2) {
    this->setX(point_2.getX() - point_1.getX());
    this->setY(point_2.getY() - point_1.getY());
    this->setZ(point_2.getZ() - point_1.getZ());
}

double Vector::vectorLength() const {
    return sqrt(pow(this->getX(), 2) + pow(this->getY(), 2) + pow(this->getZ(), 2));
}

Vector Vector::vectorDirection() const {
    try {
        if(this->vectorZero()){
            throw VectorLengthException();
        }
        double i, j, k;
        i = this->getX() / this->vectorLength();
        j = this->getY() / this->vectorLength();
        k = this->getZ() / this->vectorLength();
        return Vector(i, j, k);
    } catch (VectorLengthException & e){
        std::cout << std::endl << e.what() << std::endl;
        return *this;
    }
}

bool Vector::vectorZero() const {
    if(this->getX() == 0 && this->getY() == 0 && this->getZ() == 0){
        return true;
    } else {
        return false;
    }
}

bool Vector::vectorParallel(const Vector &vector) const {
    try {
        if(this->vectorZero() || vector.vectorZero()){
            throw VectorLengthException();
        }
        if((this->getX() / vector.getX()) == (this->getY() / vector.getY()) == (this->getZ() == vector.getZ())){
            return true;
        } else {
            return false;
        }
    } catch (VectorLengthException & e){
        std::cout << std::endl << e.what() << std::endl;
        return false;
    }
}

bool Vector::vectorPerpendicular(const Vector &vector) const {
    try {
        if(this->vectorZero() || vector.vectorZero()){
            throw VectorLengthException();
        }
        if((this->getX()*vector.getX() + this->getY()*vector.getY() + this->getZ()*vector.getZ()) == 0){
            return true;
        } else {
            return false;
        }
    } catch (VectorLengthException & e){
        std::cout << std::endl << e.what() << std::endl;
        return false;
    }
}

Vector Vector::operator+(const Vector &vector) const {
    double x = this->getX() + vector.getX();
    double y = this->getY() + vector.getY();
    double z = this->getZ() + vector.getZ();
    Vector vector_sum;
    vector_sum.setX(x); vector_sum.setY(y); vector_sum.setZ(z);
    return vector_sum;
}

Vector Vector::operator-(const Vector &vector) const {
    double x = this->getX() - vector.getX();
    double y = this->getY() - vector.getY();
    double z = this->getZ() - vector.getZ();
    Vector vector_sub;
    vector_sub.setX(x); vector_sub.setY(y); vector_sub.setZ(z);
    return vector_sub;
}

Vector Vector::operator*(double r) const {
    double x = this->getX() * r;
    double y = this->getY() * r;
    double z = this->getZ() * r;
    Vector vector;
    vector.setX(x); vector.setY(y); vector.setZ(z);
    return vector;
}

double Vector::operator*(const Vector &vector) const {
    double a = this->getX() + vector.getX();
    double b = this->getY() + vector.getY();
    double c = this->getZ() + vector.getZ();
    return a + b + c;
}

Vector Vector::operator^(const Vector &vector) const {
    double x = this->getY() * vector.getZ() - this->getZ() * vector.getY();
    double y = this->getZ() * vector.getX() - this->getX() * vector.getZ();
    double z = this->getX() * vector.getY() - this->getY() * vector.getX();
    Vector vector_new;
    vector_new.setX(x); vector_new.setY(y); vector_new.setZ(z);
    return vector_new;
}

double Vector::operator()(const Vector &vector_1, const Vector &vector_2) const {
    Vector vector_new = *this ^ vector_1;
    return (vector_new * vector_2);
}

void Vector::printFunctions() {
    int function_choice;
    Vector vector_1;
    Vector vector_2;
    double r;

    std::cout << "Functions:" << std::endl;
    std::cout << "1 - Calculate vector length" << std::endl;
    std::cout << "2 - Calculate vector direction" << std::endl;
    std::cout << "3 - Check if the vector is equal to zero" << std::endl;
    std::cout << "4 - Check if two vectors are parallel" << std::endl;
    std::cout << "5 - Check if two vectors are perpendicular" << std::endl;
    std::cout << "6 - Addition of two vectors (+)"<< std::endl;
    std::cout << "7 - Subtraction of two vectors (-)"<< std::endl;
    std::cout << "8 - Multiplication of vector with a number (*r)"<< std::endl;
    std::cout << "9 - Scalar multiplication of two vectors (*vector)"<< std::endl;
    std::cout << "10 - Vector multiplication of two vectors (^)"<< std::endl;
    std::cout << "11 - Mixed product of three vectors (())"<< std::endl;
    std::cout << "0 - Quit" << std::endl;
    std::cout << "Please select a function:";
    std::cin >> function_choice;

    while(function_choice > 11){
        std::cout << "Please enter a valid function number:";
        std::cin >> function_choice;
    }

    switch(function_choice){
        case 0:
            exit(0);
        case 1:
            std::cout << "Vector length is " << this->vectorLength() << std::endl;
            selectNewFunction(this);
            break;
        case 2:
            std::cout << "Vector direction is " << this->vectorDirection() << std::endl;
            selectNewFunction(this);
            break;
        case 3:
            std::cout << "Does the vector equals zero? ";
            if(this->vectorZero()){
                std::cout << "Yes!" << std::endl;
            } else {
                std::cout << "No!" << std::endl;
            }
            selectNewFunction(this);
            break;
        case 4:
            std::cout << "Please enter values for the second vector" << std::endl;
            std::cin >> vector_1;
            std::cout << "Is " << *this << " parallel to " << vector_1 << " ? ";
            if(this->vectorParallel(vector_1)){
                std::cout << "Yes!" << std::endl;
            } else {
                std::cout << "No!" << std::endl;
            }
            selectNewFunction(this);
            break;
        case 5:
            std::cout << "Please enter values for the second vector" << std::endl;
            std::cin >> vector_1;
            std::cout << "Is " << *this << " perpendicular to " << vector_1 << " ? ";
            if(this->vectorPerpendicular(vector_1)){
                std::cout << "Yes!" << std::endl;
            } else {
                std::cout << "No!" << std::endl;
            }
            selectNewFunction(this);
            break;
        case 6:
            std::cout << "Please enter values for the second vector" << std::endl;
            std::cin >> vector_1;
            std::cout << "The sum of " << *this << " + " << vector_1 << " = " << *this + vector_1 << std::endl;
            selectNewFunction(this);
            break;
        case 7:
            std::cout << "Please enter values for the second vector" << std::endl;
            std::cin >> vector_1;
            std::cout << "The subtraction of " << *this << " - " << vector_1 << " = " << *this - vector_1 << std::endl;
            selectNewFunction(this);
            break;
        case 8:
            std::cout << "Please enter values for r:";
            std::cin >> r;
            std::cout << *this << " * " << r << " = " << *this * r << std::endl;
            selectNewFunction(this);
            break;
        case 9:
            std::cout << "Please enter values for the second vector" << std::endl;
            std::cin >> vector_1;
            std::cout << "The scalar multiplication of " << *this << " * " << vector_1 << " = " << *this * vector_1 << std::endl;
            selectNewFunction(this);
            break;
        case 10:
            std::cout << "Please enter values for the second vector" << std::endl;
            std::cin >> vector_1;
            std::cout << "The vector multiplication of " << *this << " ^ " << vector_1 << " = " << (*this ^ vector_1) << std::endl;
            selectNewFunction(this);
            break;
        case 11:
            std::cout << "Please enter values for the second vector" << std::endl;
            std::cin >> vector_1;
            std::cout << "Please enter values for the third vector" << std::endl;
            std::cin >> vector_2;
            std::cout << "The mixed product of " << *this << " (" << vector_1 << ", " << vector_2 << ") = " << (*this)(vector_1, vector_2) << std::endl;
            selectNewFunction(this);
            break;
        default:
            std::cout << "Created by Dimitar Banev - github.com/devastion" << std::endl;
            printFunctions();
            break;
    }
}
