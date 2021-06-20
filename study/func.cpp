#include <iostream>
#include <string>
#include "mcq.h"
#include "saq.h"
#include "func.h"


void start()
{
	cout << "1. �������� ";
	cout << "2. ����Ǯ�� ";
	cout << "3. ����ä�� �� ����ǥ ��� ";
	cout << "4. ���α׷� ����" << endl;
	cout << "�޴��� �������ּ��� : ";
}
bool noQuestion(bool check)
{
	if (!check) {
		cout << "������ ������ �����ϴ�. ������ �������ּ���." << endl;
		return true;
	}
	else
		return false;

}
bool noContest(bool check)
{
	if (!check) {
		cout << "����ȴ������ �����ϴ�. ������ Ǯ���ּ���." << endl;
		return true;
	}
	else
		return false;
	
}
bool case1(mcq* q1, saq* q2)
{
	cout << "==������ 4���׿� ���� �����Դϴ�==" << endl;

	for (int i = 1; i <= 4; i++)
	{
		string text;
		cout << i << "�� ������ �Է����ּ���" << endl;
		cin >> text;
		q1->setProblem(text);
		for (int j = 0; j < 4; j++)
		{
			string answer;
			cout << (j + 1) << "��° ���⸦ �Է����ּ��� : ";
			cin >> answer;
			q1->setChoice_list(answer, j);
		}
		string result;
		cout << "���� �Է����ּ��� : ";
		cin >> result;
		q1->setCorrect_ans(result);
		cout << "������ �Է����ּ��� : ";
		int score;
		cin >> score;
		q1->setScore(score);
		cout << "----------" << endl;
		q1++;
	}
	cout << "==�ְ��� 2���׿� ���� �����Դϴ�==" << endl;
	for (int i = 1; i <= 2; i++)
	{
		cout << (i + 4) << "�� ������ �Է����ּ���" << endl;
		string text;
		cin >> text;
		q2->setProblem(text);
		cout << "���� �Է����ּ��� : ";
		string result;
		cin >> result;
		q2->setCorrect_ans(result);
		cout << "������ �Է����ּ��� : ";
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
	cout << "������ �����մϴ�.====================" << endl;
	for (int i = 1; i <= 6; i++)
	{
		cout << i << "�� �����Դϴ�." << endl;
		//cout << question1[i-1].getAns() << endl;

		if (i <= 4)
		{
			cout << q1->getProblem() << endl;
			for (int j = 0; j < 4; j++)
			{
				cout << j + 1 << ". " << q1->getChoice_list(j) << endl;
			}
			cout << "�� : ";

			int result;
			cin >> result;
			q1->setAns(result);
			q1++;
		}
		else
		{
			cout << q2->getProblem() << endl;
			cout << "�� : ";

			string result;
			cin >> result;
			q2->setAns(result);
			q2++;
		}


		if (i <= 5)
			cout << "====================" << endl;
		else
			cout << "������ �����մϴ�." << endl;
	}
	return true;
}
void case3(mcq* q1, saq* q2)
{
	cout << "ä���� �����մϴ�" << endl;
	int score = 0;
	for (int i = 1; i <= 6; i++)
	{
		cout << i << "�� ���� : ";
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
	cout << "�� ���� : " << score << endl;
}

void missInput()
{
	cout << "�Է� �ٽ� ���ּ���." << endl;
}
void initpointer(mcq* q1, mcq arr1[], saq* q2, saq arr2[])
{
	q1 = arr1;
	q2 = arr2;
}