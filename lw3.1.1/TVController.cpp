#include "TVController.hpp"
#include <exception>
#include <functional>
#include <iostream>
#include <print>
#include <string>

namespace err
{
    inline constexpr std::string_view MSG_TV_OFF      = "TV is turned off";
    inline constexpr std::string_view MSG_TV_ON       = "TV is turned on";
    inline constexpr std::string_view MSG_CH_SWITCHED = "Channel switched to: {}";
    inline constexpr std::string_view MSG_CH_INFO     = "Channel is: {}";
    inline constexpr std::string_view MSG_ERROR       = "ERROR";
}

namespace cmd
{
    inline constexpr std::string_view ON          = "TurnOn";
    inline constexpr std::string_view OFF         = "TurnOff";
    inline constexpr std::string_view INFO        = "Info";
    inline constexpr std::string_view SELECT_PREV = "SelectPreviousChannel";
    inline constexpr std::string_view SELECT      = "SelectChannel";
}

// TODO: const
TVController::TVController()
{
    this->m_commands[cmd::ON]          = std::bind(&TVController::TurnOn, this);
    this->m_commands[cmd::OFF]         = std::bind(&TVController::TurnOff, this);
    this->m_commands[cmd::INFO]        = std::bind(&TVController::Info, this);
    this->m_commands[cmd::SELECT_PREV] = std::bind(&TVController::SelectPreviousChannel, this);
}

void TVController::TurnOn()
{
    m_tv.TurnOn();
    std::println(err::MSG_TV_ON);
}

void TVController::TurnOff()
{
    m_tv.TurnOff();
    std::println(err::MSG_TV_OFF);
}

void TVController::SelectChannel(int channel)
{
    try
    {
        m_tv.SetChannel(channel);
        std::println(err::MSG_CH_SWITCHED, this->m_tv.GetChannel());
    }
    catch (std::exception& _)
    {
        std::println(err::MSG_ERROR);
    }
}

void TVController::Info()
{
    if (!this->m_tv.IsTurnedOn())
    {
        std::println(err::MSG_TV_OFF);
        return;
    }
    std::println(err::MSG_TV_ON);
    std::println(err::MSG_CH_INFO, this->m_tv.GetChannel());
}

void TVController::SelectPreviousChannel()
{
    try
    {
        this->m_tv.SelectPreviousChannel();
        std::println(err::MSG_CH_SWITCHED, this->m_tv.GetChannel());
    }
    catch (std::exception& _)
    {
        std::println(err::MSG_ERROR);
    }
}

void TVController::Run()
{
    std::string command;

    while (std::cin >> command)
    {
        if (command == cmd::SELECT)
        {
            int channel = 0;
            if (std::cin >> channel)
            {
                SelectChannel(channel);
            }
            else
            {
                std::cin.clear();
                std::println(err::MSG_ERROR);
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
                std::println(err::MSG_ERROR);
            }
        }
        std::getline(std::cin, command);
    }
}
