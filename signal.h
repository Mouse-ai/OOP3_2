#ifndef OOP3_2_SIGNAL_H
#define OOP3_2_SIGNAL_H

#include <functional>
#include <vector>

class Signal
{
private:
    std::vector<std::function<void()>> handlers;

public:
    void connect(std::function<void()> handler);
    void send();
};

#endif