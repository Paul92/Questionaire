#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Question{

    private:
        string question;
        string correctAnswer;
        vector<string> answers;

    public:
        Question(string);
        Question(ifstream);

        void setCorrectAnswer(string);
        void addAnswer(string);

        void readAnswer(ifstream f);

        string getQuestion();
        vector<string> getAnswers();
        string getCorrectAnswer();

        bool validate();
};

#endif
