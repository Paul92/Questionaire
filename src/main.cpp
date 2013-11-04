#include <QApplication>
#include <QFont>
#include "questionDialog.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    QApplication app(argc, argv);
QFont newFont("Arial", 12);
QApplication::setFont(newFont);
    ifstream f("intrebari.txt");
    QuestionDialog q(f);
    q.addQuestion();
    q.display();
    q.SetLayout();
   q.show();
    return app.exec();
}

