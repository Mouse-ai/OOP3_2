

#include "model.h"
Model::Model():a(20),b(50),c(80) {

}
int Model::getA() const
{
    return a;
}
int Model::getB() const {
    return b;
}
int Model::getC() const {
    return c;
}
void Model::setA(int value)
{
    int oldA = a;
    int oldB = b;
    int oldC = c;
    if (value < minValue)
        value = minValue;

    if (value > maxValue)
        value = maxValue;
    a = value;

    if (a >  b) {
        b = a;
    }
    if (b > c ) {
        c = b;
    }
    if (a != oldA || b != oldB || c != oldC)
    {
        changed.send();
    }

}
void Model::setC(int value)
{
    int oldA = a;
    int oldB = b;
    int oldC = c;
    if (value < minValue)
        value = minValue;

    if (value > maxValue)
        value = maxValue;
    c = value;

    if (b > c) {
        b = c;
    }
    if (a > b ) {
        a = b;
    }
    if (a != oldA || b != oldB || c != oldC)
    {
        changed.send();
    }

}
void Model::setB(int value) {
    int oldA = a;
    int oldB = b;
    int oldC = c;
    if (value < a)
        b = a;
    else if (value > c)
        b = c;
    else
        b = value;
    if (a != oldA || b != oldB || c != oldC)
    {
        changed.send();
    }
}
void Model::connectChanged(std::function<void()> handler)
{
    changed.connect(handler);
}
int Model::getMinValue() const
{
    return minValue;
}

int Model::getMaxValue() const
{
    return maxValue;
}