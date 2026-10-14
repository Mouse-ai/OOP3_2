//
// Created by alexei on 14.10.2026.
//

#ifndef UNTITLED1_MODEL_H
#define UNTITLED1_MODEL_H
#include "signal.h"
#include <fstream>
class Model {
private:
    int a;
    int b;
    int c;
    static constexpr int minValue = 0;
    static constexpr int maxValue = 100;
    Signal changed;
    void save() const;
public:
    Model();
    int getA() const;
    int getB() const;
    int getC() const;

    void setA(int value);
    void setB(int value);
    void setC(int value);
    void connectChanged(std::function<void()> handler);
    int getMinValue() const;
    int getMaxValue() const;
    void initialize();


};


#endif //UNTITLED1_MODEL_H
