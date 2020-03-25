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
	Question * questions;
};

void addQuiz();
void showQuiz();
