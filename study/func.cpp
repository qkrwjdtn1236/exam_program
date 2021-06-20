#include <iostream>
#include <string>
#include "mcq.h"
#include "saq.h"
#include "func.h"


void start()
{
	cout << "1. 문제출제 ";
	cout << "2. 문제풀기 ";
	cout << "3. 문제채점 및 성적표 출력 ";
	cout << "4. 프로그램 종료" << endl;
	cout << "메뉴를 선택해주세요 : ";
}
bool noQuestion(bool check)
{
	if (!check) {
		cout << "출제된 문제가 없습니다. 문제를 출제해주세요." << endl;
		return true;
	}
	else
		return false;

}
bool noContest(bool check)
{
	if (!check) {
		cout << "제출된답안지가 없습니다. 문제를 풀어주세요." << endl;
		return true;
	}
	else
		return false;
	
}
bool case1(mcq* q1, saq* q2)
{
	cout << "==객관식 4문항에 대한 출제입니다==" << endl;

	for (int i = 1; i <= 4; i++)
	{
		string text;
		cout << i << "번 문제를 입력해주세요" << endl;
		cin >> text;
		q1->setProblem(text);
		for (int j = 0; j < 4; j++)
		{
			string answer;
			cout << (j + 1) << "번째 보기를 입력해주세요 : ";
			cin >> answer;
			q1->setChoice_list(answer, j);
		}
		string result;
		cout << "답을 입력해주세요 : ";
		cin >> result;
		q1->setCorrect_ans(result);
		cout << "배점을 입력해주세요 : ";
		int score;
		cin >> score;
		q1->setScore(score);
		cout << "----------" << endl;
		q1++;
	}
	cout << "==주관식 2문항에 대한 출제입니다==" << endl;
	for (int i = 1; i <= 2; i++)
	{
		cout << (i + 4) << "번 문제를 입력해주세요" << endl;
		string text;
		cin >> text;
		q2->setProblem(text);
		cout << "답을 입력해주세요 : ";
		string result;
		cin >> result;
		q2->setCorrect_ans(result);
		cout << "배점을 입력해주세요 : ";
		int score;
		cin >> score;
		q2->setScore(score);
		cout << "----------" << endl;
		q2++;
	}
	return true;
}

bool case2(mcq* q1, saq* q2)
{
	cout << "시험을 시작합니다.====================" << endl;
	for (int i = 1; i <= 6; i++)
	{
		cout << i << "번 문제입니다." << endl;
		//cout << question1[i-1].getAns() << endl;

		if (i <= 4)
		{
			cout << q1->getProblem() << endl;
			for (int j = 0; j < 4; j++)
			{
				cout << j + 1 << ". " << q1->getChoice_list(j) << endl;
			}
			cout << "답 : ";

			int result;
			cin >> result;
			q1->setAns(result);
			q1++;
		}
		else
		{
			cout << q2->getProblem() << endl;
			cout << "답 : ";

			string result;
			cin >> result;
			q2->setAns(result);
			q2++;
		}


		if (i <= 5)
			cout << "====================" << endl;
		else
			cout << "시험을 종료합니다." << endl;
	}
	return true;
}
void case3(mcq* q1, saq* q2)
{
	cout << "채점을 시작합니다" << endl;
	int score = 0;
	for (int i = 1; i <= 6; i++)
	{
		cout << i << "번 문제 : ";
		if (i <= 4)
		{
			if (q1->getAns() == stoi(q1->getCorrect_ans()))
			{
				cout << "O" << endl;

			}
			else
			{
				cout << "X" << endl;
			}
			score += q1->earnPoint();
			q1++;
		}
		else
		{
			if (q2->getAns() == q2->getCorrect_ans())
				cout << "O" << endl;
			else
				cout << "X" << endl;
			score += q2->earnPoint();
			q2++;
		}
	}
	cout << "총 점수 : " << score << endl;
}

void missInput()
{
	cout << "입력 다시 해주세요." << endl;
}
void initpointer(mcq* q1, mcq arr1[], saq* q2, saq arr2[])
{
	q1 = arr1;
	q2 = arr2;
}