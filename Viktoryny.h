#pragma once

#include<iostream>
#include<string>
using namespace std;

struct Question {
	string name;	
	string rightAnswer;	
};

struct Quiz {
	string NameViktoryna;
	Question  questions[5];
};

void addQuiz();
void showQuiz();
void init();
void insertQuiz(Quiz quiz );
void passWuiz();

