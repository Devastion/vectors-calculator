//
// Created by Dimitar Banev on 07/05/2021.
//

#ifndef VECTORS_CALCULATOR_ELEMENT_HPP
#define VECTORS_CALCULATOR_ELEMENT_HPP

#include <iostream>
#include <cmath>

class Element {
public:
    virtual std::ostream& output(std::ostream& out) const = 0;
    virtual std::istream& input(std::istream& in) = 0;
    virtual void printFunctions() = 0;
};

static inline void selectNewFunction(Element* element){
    char choice;
    std::cout << "Do you want to select new function? (y/n):";
    std::cin >> choice;

    while(choice != 'y' && choice != 'n'){
        std::cout << "Do you want to select new function? (y/n):";
        std::cin >> choice;
    }

    if(choice == 'y'){
        element->printFunctions();
    } else if(choice == 'n') {
        char choice_element;
        std::cout << "Do you want to select a new element? (y/n):";
        std::cin >> choice_element;

        while(choice_element != 'y' && choice_element != 'n'){
            std::cout << "Do you want to select a new element? (y/n):";
            std::cin >> choice_element;
        }

        if(choice_element == 'n'){
            exit(0);
        }
    }
}

#endif //VECTORS_CALCULATOR_ELEMENT_HPP
