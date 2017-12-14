#ifndef DUMBAI_H
#define DUMBAI_H

class DumbAI
{
private:
	
	int m_guess;
	
public:
	DumbAI();
	int guess();
	void tooHigh();
	void tooLow();
};

#endif
