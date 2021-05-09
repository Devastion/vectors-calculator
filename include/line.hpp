//
// Created by Dimitar Banev on 07/05/2021.
//

#ifndef VECTORS_CALCULATOR_LINE_HPP
#define VECTORS_CALCULATOR_LINE_HPP

#include "vector.hpp"

class Line : public Vector{
private:
    Point firstPoint;
    Point secondPoint;
    Vector vectorConstructor;

public:
    Line();
    ~Line();
    Line(const Point& point, const Vector& vector);
    Line(const Point& point_1, const Point& point_2);
    Line(const Line& line);

    Point getFirstPoint() const;
    Point getSecondPoint() const;

    Vector lineDirection() const;
    Vector lineNormal() const;
    double lineAngle(const Line& line) const;

    bool operator+(const Point& point) const;
    bool operator||(const Line& line) const;
    bool operator==(const Line& line) const;
    bool operator&&(const Line& line) const;
    bool operator!=(const Line& line) const;
    bool operator|(const Line& line) const;

    inline std::ostream& output(std::ostream& out) const override;
    inline std::istream& input(std::istream& in) override;

    void printFunctions() override;
};

std::ostream &Line::output(std::ostream &out) const{
    return out << "Line \n" << "First Point: " << Line::firstPoint << "\n Second Point: " << Line::secondPoint << "\n Vector: " << Line::vectorConstructor;
}

std::istream &Line::input(std::istream &in) {
    int line_init_choice;
    Point point_1, point_2;
    Vector vector;
    std::cout << "Please select an option:" << std::endl;
    std::cout << "1 - Initialize the line from a vector and a point" << std::endl;
    std::cout << "2 - Initialize the the line from two points" << std::endl;
    std::cout << "0 - Quit" << std::endl;
    std::cout << "Please select an option:";
    std::cin >> line_init_choice;

    while(line_init_choice < 0 || line_init_choice > 2) {
        std::cout << "Please select an option:";
        std::cin >> line_init_choice;
    }

    switch(line_init_choice){
        case 0:
            exit(0);
        case 1:
            std::cout << "Please enter values for the vector:" << std::endl;
            std::cin >> vector;
            std::cout << "Please enter values for the point:" << std::endl;
            std::cin >> point_1;
            *this = Line(vector, point_1);
            break;
        case 2:
            std::cout << "Please enter values for the first point:" << std::endl;
            std::cin >> point_1;
            std::cout << "Please enter values for the second point:" << std::endl;
            std::cin >> point_2;
            *this = Line(point_1, point_2);
            break;
        default:
            std::cout << "Created by Dimitar Banev - github.com/devastion";
            break;
    }

    return in;
}

inline std::ostream &operator<<(std::ostream &out, const Line& line) {
    return line.output(out);
}

inline std::istream &operator>>(std::istream &in, Line& line){
    return line.input(in);
}

#endif //VECTORS_CALCULATOR_LINE_HPP
