#include "TVController.hpp"
#include <exception>
#include <functional>
#include <iostream>
#include <print>
#include <string>

namespace
 {
    inline constexpr std::string_view MSG_TV_OFF      = "TV is turned off";
    inline constexpr std::string_view MSG_TV_ON       = "TV is turned on";
    inline constexpr std::string_view MSG_CH_SWITCHED = "Channel switched to: {}";
    inline constexpr std::string_view MSG_CH_INFO     = "Channel is: {}";
    inline constexpr std::string_view MSG_ERROR       = "ERROR";
}

TVController::TVController()
{
    this->m_commands["TurnOn"]                = std::bind(&TVController::TurnOn, this);
    this->m_commands["TurnOff"]               = std::bind(&TVController::TurnOff, this);
    this->m_commands["Info"]                  = std::bind(&TVController::Info, this);
    this->m_commands["SelectPreviousChannel"] = std::bind(&TVController::SelectPreviousChannel, this);
}

void TVController::TurnOn()
{
    m_tv.TurnOn();
    std::println(MSG_TV_ON);
}

void TVController::TurnOff()
{
    m_tv.TurnOff();
    std::println(MSG_TV_OFF);
}

void TVController::SelectChannel(int channel)
{
    try
    {
        m_tv.SetChannel(channel);
        std::println(MSG_CH_SWITCHED, this->m_tv.GetChannel());
    }
    catch (std::exception& _)
    {
        std::println(MSG_ERROR);
    }
}

void TVController::Info()
{
    if (!this->m_tv.IsTurnedOn())
    {
        std::println(MSG_TV_OFF);
        return;
    }
    std::println(MSG_TV_ON);
    std::println(MSG_CH_INFO, this->m_tv.GetChannel());
}

void TVController::SelectPreviousChannel()
{
    try
    {
        this->m_tv.SelectPreviousChannel();
        std::println(MSG_CH_SWITCHED, this->m_tv.GetChannel());
    }
    catch (std::exception& _)
    {
        std::println(MSG_ERROR);
    }
}

void TVController::Run()
{
    std::string command;

    while (std::cin >> command)
    {
        if (command == "SelectChannel")
        {
            int channel = 0;
            if (std::cin >> channel)
            {
                SelectChannel(channel);
            }
            else
            {
                std::cin.clear();
                std::println(MSG_ERROR);
            }
        }
        else
        {
            auto it = m_commands.find(command);
            if (it != m_commands.end())
            {
                it->second();
            }
            else
            {
                std::println(MSG_ERROR);
            }
        }
        std::getline(std::cin, command);
    }
}
