//
// Created by alexei on 14.10.2026.
//

#include "signal.h"

void Signal::connect(std::function<void()> handler) {
    handlers.push_back(handler);
}
void Signal::send()
{
    for (auto &handler : handlers)
    {
        handler();
    }
}