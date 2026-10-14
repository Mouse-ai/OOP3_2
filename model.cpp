

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

}
void Model::setC(int value)
{
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

}
void Model::setB(int value) {
    if (value < a)
        b = a;
    else if (value > c)
        b = c;
    else
        b = value;
}