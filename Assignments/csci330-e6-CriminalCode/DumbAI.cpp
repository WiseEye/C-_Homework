#include "DumbAI.h"

DumbAI::DumbAI()
{
    int m_guess = 50;
}

int DumbAI::guess() 
{ 
    return m_guess;
}

void DumbAI::tooHigh()
{
    m_guess--;
}

void DumbAI::tooLow()
{
    m_guess++;
}
