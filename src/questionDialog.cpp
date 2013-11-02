#include "questionDialog.h"
#include <QtGui>
#include <QString>
#include <iostream>
#include <cstdlib>

QuestionDialog::QuestionDialog(ifstream &f, QWidget *parent): QDialog(parent), Question(f), file(f){
        score = 0;
}

void QuestionDialog::addQuestion(){
    questionLabel = new QLabel;
    questionLabel ->setText(QString::fromStdString(question));
    questionLabel ->setWordWrap(true);
}

void QuestionDialog::addImage(){
    imageLabel    = new QLabel;
    imageLabel    -> setPixmap(QString::fromStdString(imageLink));
}

void QuestionDialog::addButtons(){
    for(unsigned int i = 0; i < answers.size(); i++){
        string label("A");
        label[0] += i;
        buttons.push_back(new QPushButton(QString::fromStdString(label)));
    }
}

void QuestionDialog::addAnswers(){
    for(unsigned int i = 0; i<answers.size(); i++){
        string label("A");
        label[0] += i;
        answerLabels.push_back(new QLabel(QString::fromStdString(label+". "+answers[i])));
    }
}


void QuestionDialog::generateLayout(){

    buttonLayout = new QHBoxLayout;
    for(unsigned int i = 0; i < buttons.size(); i++){
        buttonLayout -> addWidget(buttons[i]);
    }
    buttonLayout -> addStretch();

    answerLabelsLayout = new QVBoxLayout;
    for(unsigned int i = 0; i < answerLabels.size(); i++){
        answerLabelsLayout -> addWidget(answerLabels[i]);
    }

    questionAndImage = new QVBoxLayout;
    questionAndImage -> addWidget(questionLabel);
    questionAndImage -> addWidget(imageLabel);

    mainLayout = new QVBoxLayout;
    mainLayout -> addLayout(questionAndImage);
    mainLayout -> addLayout(answerLabelsLayout);
    mainLayout -> addLayout(buttonLayout);
    mainLayout -> addStretch();

    this -> setFixedSize(640, 480);
}

void QuestionDialog::SetLayout(){
    setLayout(mainLayout);
}

void QuestionDialog::addSlots(){
    for(unsigned int i = 0; i < buttons.size(); i++){
        connect(buttons[i], SIGNAL(clicked()), this, SLOT(answerChoosen()));
    }
}

void QuestionDialog::display(){
    addQuestion();
    addImage();
    addButtons();
    addAnswers();
    generateLayout();
    addSlots();
}

void clearLayout(QLayout* layout, bool deleteWidgets = true){
    while(QLayoutItem* item = layout->takeAt(0)){
        if(deleteWidgets){
            if(QWidget* widget = item->widget())
                delete widget;
        }
        if(QLayout* childLayout = item->layout())
            clearLayout(childLayout, deleteWidgets);
        delete item;
    }
}

void QuestionDialog::resetDialog(){
    clearLayout(mainLayout);
    delete mainLayout;
    buttons.resize(0);
    answerLabels.resize(0);
}

void QuestionDialog::answerChoosen(){
    QPushButton *emitter = (QPushButton*)QObject::sender();
    int buttonId = (emitter -> text()).toUtf8()[0] - 'A';
    if(correctAnswer == answers[buttonId])
        score++;
    char c[150];
    sprintf(c, "Ai raspuns corect la %d din %d intrebari", score, noOfQuestions);
    question = string(c);
    reset();
    resetDialog();
    assign(file);
    display();
    setLayout(mainLayout);
}

