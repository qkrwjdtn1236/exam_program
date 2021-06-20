#pragma once
#ifndef fUNC_H
#define fUNC_H

#include "mcq.h"
#include "saq.h"

void start();
bool case1(mcq* q1, saq* q2);
bool case2(mcq* q1, saq* q2);
void case3(mcq* q1, saq* q2);
void initpointer(mcq* q1, mcq arr1[], saq* q2, saq arr2[]);
bool noQuestion(bool check);
bool noContest(bool check);
void missInput();

#endif // !function_H