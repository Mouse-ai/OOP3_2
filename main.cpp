#include <iostream>
#include "model.h"
#include "signal.h"
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
    Signal signal;

    signal.connect([]()
    {
        std::cout << "First handler" << std::endl;
    });

    signal.connect([]()
    {
        std::cout << "Second handler" << std::endl;
    });

    signal.send();

    return 0;
    return 0;
}