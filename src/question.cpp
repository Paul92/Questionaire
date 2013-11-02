#include "question.h"
#include <string>
#include <iostream>
#include <algorithm>

void Question::setCorrectAnswer(string answer){
    answers.push_back(answer);
    correctAnswer = answer;
}

void Question::addAnswer(string answer){
    answers.push_back(answer);
}

void Question::setImage(ifstream &f){
    getline(f, imageLink);
}

bool Question::addAnswer(ifstream& f){
    string a;
    getline(f, a);
    if(a.size() == 0){
        return false;
    }
    string answer = a.substr(1, a.size()-1);
    if(a[0] == '+')
        setCorrectAnswer(answer);
    else
        addAnswer(answer);
    return true;
}

void Question::assign(ifstream &f){
    getline(f, question);
    getline(f, imageLink);
    while(addAnswer(f));
    random_shuffle(answers.begin(), answers.end());
    if(answers.size() > 0)
        noOfQuestions++;
}

Question::Question(ifstream& f){
    noOfQuestions = 0;
    assign(f);
}

void Question::reset(){
    answers.resize(0);
}

bool Question::validate(){
/*    if(!correctAnswer.empty() && answers.size() > 1)
        return true;
    else*/
        return false;
}

//DEBUG
void Question::print(){
    std::cout<<"Question: "<<question<<"\nImage: "<<imageLink<<"\nAnswers: ";
    for(unsigned int i=0; i<answers.size(); i++)
        std::cout<<answers[i]<<'\n';
}
