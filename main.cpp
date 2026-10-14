#include <iostream>
#include "model.h"

int main()
{
    Model model;

    std::cout << model.getA() << " "
              << model.getB() << " "
              << model.getC() << std::endl;

    model.setA(90);

    std::cout << model.getA() << " "
              << model.getB() << " "
              << model.getC() << std::endl;

    model.setC(30);

    std::cout << model.getA() << " "
              << model.getB() << " "
              << model.getC() << std::endl;

    return 0;
}