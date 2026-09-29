#pragma once

#include "TVSet.hpp"
#include <functional>
#include <string>

class TVController
{
public:
    TVController();
    void Run();

    void Info();
    void TurnOn();
    void TurnOff();
    void SelectChannel(int channel);
    void SelectPreviousChannel();

private:
    TVSet m_tv;
    std::unordered_map<std::string, std::function<void()>> m_commands;
};
