#include <iostream>
#include <cstdlib>
#include <ctime>

#include "UserInput.h"
#include "DumbAI.h"
#include "ExpertAI.h"

using namespace std;

int main()
{
	srand(time(NULL));

	int tries = 0;
	UserInput in;
	DumbAI aiDumb;
	ExpertAI aiExpert;
	int guess = -1;
	int num = (rand() % 100) +1;

	cout << "The secret number is " << num << endl;
	cout << "Would you like to use the dumb AI (d) or expert AI (e)? ";
	char choice = in.readChar();
	while (guess != num)
	{
		tries++;
		if (choice == 'd')
		{
			guess = aiDumb.guess();
			std::cout << guess << std::endl;
			if (guess > num)
				aiDumb.tooHigh();
			else if (guess < num)
				aiDumb.tooLow();
		}
		else if (choice == 'e')
		{
			guess = aiExpert.guess();
			std::cout << guess << std::endl;
			if (guess > num)
				aiExpert.tooHigh();
			else if (guess < num)
				aiExpert.tooLow();
		}
		if (tries > 100)
		{
			cout << "AI did not guess the correct number." << endl;
			break;
		}
	}

	cout << "The AI needed " << tries << " tries to guess number " << num << endl;
}
