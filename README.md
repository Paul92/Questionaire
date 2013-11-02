Questionnaire
============

This is a simple application which generates a questionnaire, based on a input
file, called intrebari.txt. It's format is as follows:

'question
image
+ answer1
- answer2
- answer3
'

There is no limit on number of answers or number of questions. 
Every answer MUST have a + or a - in front of it, followed by a blank.
+ indicates the correct answer, so there should be only one answer with +
(otherwise there is undefined behaviour). - indicates wrong answers.
Between 2 questions must be an empty line.

This project was realised for learning purposes. It provides no guarantee and
it should not be taken as an example, because it may contain bad prgramming
practices.
