//
// Created by Dimitar Banev on 07/05/2021.
//

#ifndef VECTORS_CALCULATOR_VECTORLENGTHEXCEPTION_HPP
#define VECTORS_CALCULATOR_VECTORLENGTHEXCEPTION_HPP

#include <exception>

class VectorLengthException : public std::exception{
public:
    const char* what() const noexcept override{
        return "The vector is equal to zero!!!";
    }
};


#endif //VECTORS_CALCULATOR_VECTORLENGTHEXCEPTION_HPP
