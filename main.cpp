#include "include/element.hpp"
#include "include/point.hpp"
#include "include/vector.hpp"
#include "include/line.hpp"
#include "include/segment.hpp"
#include "include/triangle.hpp"
#include "include/tetrahedron.hpp"

int main() {
    do {
        int element_choice;
        Point point_init;
        Vector vector_init;
        Line line_init;
        Segment segment_init;
        Triangle triangle_init;
        Tetrahedron tetrahedron_init;

        std::cout << "Please choose an element:" << std::endl;
        std::cout << "1 - Point" << std::endl;
        std::cout << "2 - Vector" << std::endl;
        std::cout << "3 - Line" << std::endl;
        std::cout << "4 - Segment" << std::endl;
        std::cout << "5 - Triangle" << std::endl;
        std::cout << "6 - Tetrahedron" << std::endl;
        std::cout << "0 - Quit" << std::endl;
        std::cout << "Please select a choice:";
        std::cin >> element_choice;

        while(element_choice > 6 || element_choice < 0) {
            std::cout << "Please select a valid choice:";
            std::cin >> element_choice;
        }

        switch(element_choice){
            case 0:
                exit(0);
            case 1:
                std::cout << "Enter values for the point:" << std::endl;
                std::cin >> point_init;
                point_init.printFunctions();
                break;
            case 2:
                std::cout << "Enter values for the vector:" << std::endl;
                std::cin >> vector_init;
                vector_init.printFunctions();
                break;
            case 3:
                std::cout << "Enter values for the line:" << std::endl;
                std::cin >> line_init;
                line_init.printFunctions();
                break;
            case 4:
                std::cout << "Enter values for the segment:" << std::endl;
                std::cin >> segment_init;
                segment_init.printFunctions();
                break;
            case 5:
                std::cout << "Enter values for the triangle:" << std::endl;
                std::cin >> triangle_init;
                triangle_init.setABC();
                triangle_init.printFunctions();
                break;
            case 6:
                std::cout << "Enter values for the tetrahedron:" << std::endl;
                std::cin >> tetrahedron_init;
                tetrahedron_init.setABCD();
                tetrahedron_init.printFunctions();
                break;
            default:
                std::cout << "Created by Dimitar Banev - github.com/devastion";
                break;
        }
    } while(true);
}
