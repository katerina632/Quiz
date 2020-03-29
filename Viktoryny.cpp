#include "Viktoryny.h"
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

Quiz* newQuiz;
int countQuiz = 0;
const int countQuestions = 5;
const string fileName = "Quiz.txt";

void insertQuiz(Quiz quiz)
{
    Quiz* temp = new  Quiz[countQuiz + 1]; //
    for (int i = 0; i < countQuiz; i++) {

        temp[i] = newQuiz[i];
    }



    temp[countQuiz] = quiz;
    countQuiz++;
    newQuiz = new Quiz[countQuiz];
    for (int i = 0; i < countQuiz; i++) {

        newQuiz[i] = temp[i];
    }
    delete[]temp;

}

void passWuiz()
{
    int selectQuiz = 0;
    int score = 0;

    cout << "Enter number quiz for start pass->_ ";
    cin >> selectQuiz;
    selectQuiz--;
    cout << endl;
    cout << "Vy pochaky prohodyty " << newQuiz[selectQuiz].NameViktoryna << endl;
    for (int i = 0; i < countQuestions; i++) {
        cout << newQuiz[selectQuiz].questions[i].name << endl;
        string tempAnswer = "";
        cout << "Tvoja vidpovid' ->_ ";
        cin >> tempAnswer;

        if (newQuiz[selectQuiz].questions[i].rightAnswer==tempAnswer) {
            cout << "Virno! (+20 do rezyl'tatu )"<<endl;
            score += 20;        
        }
        else{
            cout << "Nevirno! :(" << endl;

        }
        cout << "Vash rezyl'tat:" << score << "/100" << endl;
    
    }


}

void init()
{
    ifstream fin;
    fin.open(fileName);    

    bool isOpen = fin.is_open();
    if (isOpen == true) {

        while (!fin.eof()) {
            Quiz getQuiz;

            fin >> getQuiz.NameViktoryna;
            if (getQuiz.NameViktoryna != "") {

                for (int i = 0; i < countQuestions; i++) {
                    fin >> getQuiz.questions[i].name;
                    fin >> getQuiz.questions[i].rightAnswer;
                }
            }
            else {
                break;
            }
            insertQuiz(getQuiz);

        }
    }
    else {
        cout << "Error!" << endl;
    }

    fin.close();

}



void addQuiz()
{
    ofstream fout;
    fout.open(fileName, fstream::app);
    bool isOpen = fout.is_open();
    if (isOpen == true) {
       

        Quiz* temp = new  Quiz[countQuiz+1];
        for (int i = 0; i < countQuiz; i++) {

            temp[i] = newQuiz[i];
        }     
            
        cout << "Vvedit' nazvu victoryny->_ ";
        cin >> temp[countQuiz].NameViktoryna;        

        
        for (int i = 0; i < countQuestions; i++) {

            cout << "Vvedit' zapytannja " << i + 1 << "/" << countQuestions << ":";
            cin >> temp[countQuiz].questions[i].name;
            cout << "Vvedit' pravyl'nu vidpovid' ";
            cin >> temp[countQuiz].questions[i].rightAnswer;
            cout << endl;
        }

        fout << temp[countQuiz].NameViktoryna << endl;
        for (int i = 0; i < countQuestions; i++) {
            fout << temp[countQuiz].questions[i].name << endl;
            fout << temp[countQuiz].questions[i].rightAnswer << endl;
        }

        countQuiz++;
        newQuiz = new Quiz[countQuiz];
        for (int i = 0; i < countQuiz; i++) {
        
            newQuiz[i] = temp[i];
        }
        delete[]temp;

    }

    else {
        cout << "Error!" << endl;
    }

    fout.close();

}








void showQuiz()
{
    for (int i = 0; i < countQuiz; i++)
    {
        cout << i + 1 << ") " << newQuiz[i].NameViktoryna << endl;        
    }
    cout << endl;
    
}
