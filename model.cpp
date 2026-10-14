

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
        save();
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
        save();
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
        save();
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
void Model::save() const
{
    std::ofstream file("model_state.txt");

    if (file.is_open())
    {
        file << a << " " << b << " " << c;
    }
}
void Model::initialize()
{
    int loadedA = a;
    int loadedB = b;
    int loadedC = c;

    std::ifstream file("model_state.txt");

    if (file.is_open() && file >> loadedA >> loadedB >> loadedC)
    {
        if (loadedA < minValue)
            loadedA = minValue;
        if (loadedA > maxValue)
            loadedA = maxValue;

        if (loadedB < minValue)
            loadedB = minValue;
        if (loadedB > maxValue)
            loadedB = maxValue;

        if (loadedC < minValue)
            loadedC = minValue;
        if (loadedC > maxValue)
            loadedC = maxValue;

        if (loadedA > loadedB)
            loadedB = loadedA;

        if (loadedB > loadedC)
            loadedC = loadedB;

        a = loadedA;
        b = loadedB;
        c = loadedC;
    }

    changed.send();
}