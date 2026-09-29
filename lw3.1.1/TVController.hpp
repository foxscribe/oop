#pragma once

#include "TVSet.hpp"
#include <functional>
#include <string_view>

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
    std::unordered_map<std::string_view, std::function<void()>> m_commands;
};
