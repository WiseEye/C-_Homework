#ifndef ExpertAI_H
#define ExpertAI_H

class ExpertAI
{
private:
    int m_max;
    int m_min;
    int m_currentGuess;
    int m_currentMidpoint;
	// ????
	
public:
	ExpertAI();
	int guess();
	void tooHigh();
	void tooLow();
};

#endif
