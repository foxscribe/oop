#include "TVSet.hpp"
#include <stdexcept>

namespace err
{
    inline const std::string TURNED_OFF          = "turned off";
    inline const std::string INVALID_CHANNEL     = "invalid channel";
    inline const std::string NO_PREVIOUS_CHANNEL = "no previous channel";
}

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
    if (this->m_power)
    {
        return this->m_lastChannel;
    }
    return 0;
};

void TVSet::SetChannel(int channel)
{
    if (!this->m_power)
    {
        throw std::runtime_error(err::TURNED_OFF);
    }
    if (channel <= 0 || channel >= 100)
    {
        throw std::runtime_error(err::INVALID_CHANNEL);
    }
    this->m_lastChannel = this->m_currentChannel;
    this->m_currentChannel = channel;
};

void TVSet::SelectPreviousChannel()
{
    if (!this->m_power)
    {
        throw std::runtime_error(err::TURNED_OFF);
    }
    if (this->m_lastChannel == 0)
    {
        throw std::runtime_error(err::NO_PREVIOUS_CHANNEL);
    }
    int t = m_currentChannel;
    this->m_currentChannel = this->m_lastChannel;
    this->m_lastChannel = t;
};
