//
// Created by Dimitar Banev on 07/05/2021.
//

#ifndef VECTORS_CALCULATOR_EQUALPOINTEXCEPTION_HPP
#define VECTORS_CALCULATOR_EQUALPOINTEXCEPTION_HPP

#include <exception>

class EqualPointException : public std::exception{
public:
    const char* what() const noexcept override{
        return "The points can't be equal!!!";
    }
};


#endif //VECTORS_CALCULATOR_EQUALPOINTEXCEPTION_HPP
