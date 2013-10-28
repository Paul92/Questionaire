#include "question.h"

Question::Question(string q): question(q), score(0){
}

Question::Question(ifstream f): score(0){
    f>>question;
}

void Question::setCorrectAnswer(string answer){
    correctAnswer = answer;
    answers.push_back(answer);
}

void Question::addAnswer(string answer){
    answers.push_back(answer);
}

void Question::readAnswer(ifstream f){
    string a;
    f>>a;
    if(a[0] == '+')
        setCorrectAnswer(a.substr(1, a.size()-1));
    else
        this.addAnswer(a.substr(1, a.size()-1));

}

string Question::getQuestion(){
    return question;
}

vector<string> Question::getAnswers(){
    return answers;
}

string Question::getCorrectAnswer(){
    return correctAnswer;
}

bool Question::validate(){
    if(!correctAnswer.empty() && answers.size() > 1)
        return true;
    else
        return false;
}

