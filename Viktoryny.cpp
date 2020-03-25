#include "Viktoryny.h"
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

Quiz* newQuiz;
int countQuiz = 0;
int countQuestions = 5;
void addQuiz()
{
    ofstream fout;
    fout.open("Quiz.txt", fstream::app);
    bool isOpen = fout.is_open();
    if (isOpen == true) {

       

        Quiz* temp = new  Quiz[countQuiz+1];
        for (int i = 0; i < countQuiz; i++) {

            temp[i] = newQuiz[i];
        }     
            
        cout << "Vvedit' nazvu victoryny->_ ";
        cin >> temp[countQuiz].NameViktoryna;        

        temp[countQuiz].questions = new Question[countQuestions];
        for (int i = 0; i < countQuestions; i++) {

            cout << "Vvedit' zapytannja " << i + 1 << "/" << countQuestions << ":";
            cin >> temp[countQuestions].questions[i].name;
            cout << "Vvedit' pravyl'nu vidpovid' ";
            cin >> temp[countQuestions].questions[i].rightAnswer;

        }
        fout << temp[countQuiz].NameViktoryna << endl;
      
        for (int i = 0; i < countQuestions; i++) {
            fout << temp[countQuiz].NameViktoryna << endl;     

        }

        countQuiz++;
        delete newQuiz;
        newQuiz = temp;
    }

    else {
        cout << "Error!" << endl;
    }

}

void showQuiz()
{
    for (int i = 0; i < countQuiz; i++)
    {
        cout << newQuiz[i].NameViktoryna << endl;
        
    }
}
