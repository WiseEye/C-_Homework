#include "ExpertAI.h"

ExpertAI::ExpertAI()
{
    int m_max = 100;//this will become our last guess if it is to low
    int m_min = 0; //this will become our last guess if it is to high
	int m_currentGuess = 50;
    int m_currentMidpoint = 0;
}

int ExpertAI::guess()
{   
    
	return m_currentGuess;
}

void ExpertAI::tooHigh()
{   
    m_max = m_currentGuess;;
    
   if((m_max - m_min) % 2 > 0)
    {
        m_currentGuess = m_currentGuess - (((m_max - m_min) -1)  / 2);
    }
    
    else
    {
       m_currentGuess = m_currentGuess - (((m_max - m_min))  / 2);
    } 
}

void ExpertAI::tooLow()
{
    m_min = m_currentGuess;
    
	if((m_max - m_min) % 2 > 0)
    {
        m_currentGuess = m_currentGuess + (((m_max - m_min) -1)  / 2);
    }
    
    else
    {
        m_currentGuess = m_currentGuess + (((m_max - m_min))  / 2);
    } 
}

