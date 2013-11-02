#ifndef QUESTION_DIALOG_H
#define QUESTION_DIALOG_H

#include <QDialog>
#include "question.h"
class QPushButton;
class QLabel;
class QHBoxLayout;
class QVBoxLayout;

class QuestionDialog: public QDialog, public Question{
    Q_OBJECT

    public:
        QuestionDialog(ifstream&, QWidget *parent = 0);
        void display();
        void SetLayout();

        void addQuestion();
        void addImage();
        void addButtons();
        void addAnswers();
        void generateLayout();
        void addSlots();
        void resetDialog();
        void GenerateLayout();
    signals:

    private slots:
        void answerChoosen();

    private:
        vector<QPushButton*> buttons;
        vector<QLabel*> answerLabels;
        QLabel *questionLabel;
        QLabel *imageLabel;
        QHBoxLayout *buttonLayout;
        QVBoxLayout  *mainLayout, *questionAndImage, *answerLabelsLayout;

        ifstream &file;


};
#endif



