#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Question{

    protected:
        string question;
        string correctAnswer;
        vector<string> answers;
        int score;
        int noOfQuestions;
        string imageLink;

    public:
        Question(ifstream&);

        void setCorrectAnswer(string);
        void addAnswer(string);
        bool addAnswer(ifstream&);

        void setImage(string);
        void setImage(ifstream&);

        bool validate();

        void print();

        void assign(ifstream &);
        void reset();
};

#endif
