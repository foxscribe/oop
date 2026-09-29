#include "TVSet.hpp"
#include <stdexcept>

TVSet::TVSet()
{

};

void TVSet::TurnOn()
{
    this->m_power = true;
    if (this->m_currentChannel == 0)
    {
        this->m_currentChannel = 1;
    }
};

void TVSet::TurnOff()
{
    this->m_power = false;
};

bool TVSet::IsTurnedOn() const
{
    return this->m_power;
};

int TVSet::GetChannel() const
{
    if (this->m_power)
    {
        return this->m_currentChannel;
    }
    return 0;
};

int TVSet::GetLastChannel() const
{
    if (this->m_power && !(this->m_lastChannel == 0))
    {
        return this->m_lastChannel;
    }
    return 0;
};

void TVSet::SetChannel(int channel)
{
    if (!this->m_power)
    {
        throw std::runtime_error("turned off");
    }
    if (channel <= 0 || channel >= 100)
    {
        throw std::runtime_error("invalid channel");
    }
    this->m_lastChannel = this->m_currentChannel;
    this->m_currentChannel = channel;
};

void TVSet::SelectPreviousChannel()
{
    if (!this->m_power)
    {
        throw std::runtime_error("turned off");
    }
    if (this->m_lastChannel == 0)
    {
        throw std::runtime_error("no previous channel");
    }
    int t = m_currentChannel;
    this->m_currentChannel = this->m_lastChannel;
    this->m_lastChannel = t;
};
