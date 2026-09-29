#pragma once

class TVSet
{
public:
    TVSet();

    void TurnOn();
    void TurnOff();
    bool IsTurnedOn() const;
    int GetChannel() const;
    int GetLastChannel() const;
    void SetChannel(int channel);
    void SelectPreviousChannel();

private:
    int m_currentChannel = 0, m_lastChannel = 0;
    bool m_power = false;
};
