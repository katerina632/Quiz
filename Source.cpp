#include<iostream>
#include<string>
#include<ctime>
#include<fstream>
#include "Viktoryny.h"



using namespace std;

int main() {

	int action = 0;	
	init();
	do {
		cout << "1. Stvoryty viktorynu" << endl;
		cout << "2. Projty viktorynu (oburajet'sja zi spysky mozhlyvyh)" << endl;
		cout << "3. Vyhid" << endl << endl;
		cout << "Vuberit' diju->_ ";
		cin >> action;
		switch (action) {
		case 1:
			addQuiz();
			break;
		case 2:
			showQuiz();
			passWuiz();
			break;
		case 3:
			cout << "Good bye!" << endl;
			break;
			
		default:
			cout << "Error!" << endl;
		}

	} while (action != 3);


	


	system("pause");
	return 0;
}