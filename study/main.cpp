#include <iostream>
#include <string>
#include "func.h"
using namespace std;

bool havequestion = false;
bool contestover = false;

int main()
{
	
	int inputNum;
	
	mcq question1[4] = { mcq(),mcq() ,mcq() ,mcq() };
	saq question2[2] = { saq(),saq() };

	mcq* q1 = question1;
	saq* q2 = question2;

	while (true)
	{
		start();
		cin >> inputNum;
		
		switch (inputNum)
		{
		case 1:
			havequestion = case1(q1,q2);
			initpointer(q1, question1, q2, question2);
			break;
		case 2:

			if(noQuestion(havequestion))
				continue;

			contestover = case2(q1,q2);
			initpointer(q1, question1, q2, question2);
			break;
		case 3:
		{
			if (noContest(contestover))
				continue;
			
			case3(q1,q2);
			initpointer(q1, question1, q2, question2);
			break;
		}
		case 4:
			return 0;
			break;
		default:
			missInput();
			continue;
		}
	}

}