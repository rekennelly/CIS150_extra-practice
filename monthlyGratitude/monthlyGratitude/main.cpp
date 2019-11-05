//
//  main.cpp
//  monthlyGratitude
//
//  Created by Rachel Kennelly on 11/5/19.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

vector<string> getQuestions()
{
    ifstream inputFileStream;
    inputFileStream.open("questions.txt");
    
    if (!inputFileStream.is_open())
    {
        cout << "Can't find the questions!" << endl;
        exit(-1);
    }
    
    vector<string> gratitudeQuestions;
    
    while (!inputFileStream.eof())
    {
        string question;
        getline(inputFileStream, question);
        gratitudeQuestions.push_back(question);
    }
    return gratitudeQuestions;
}

void answerQuestion(vector<string> questions, vector<string>& answers)
{
    for (int index = 0; index < questions.size(); index++)
    {
        string answer;
        cout << questions.at(index) << endl;
        getline(cin, answer);
        answers.push_back(answer);
    }
}

string getMonth() {
    string month;
    
    cout << "What month are these questions for?" << endl;
    getline(cin, month);
    
    return month;
}

void saveQuestionsAndAnswers(vector<string> questions, vector<string> answers)
{
    ofstream outputFileStream;
    string month = getMonth();
    
    string fileName = month + "gratitude.txt";
    
    outputFileStream.open(fileName);
    
    if (!outputFileStream.is_open())
    {
        cout << "Could not open " << fileName << endl;
    }
    
    for (int index = 0; index < questions.size(); index++)
    {
        outputFileStream << questions.at(index) << endl;
        outputFileStream << answers.at(index) << endl << endl;
    }
    
    outputFileStream.close();
    
    cout << "Your answers have been exported!" << endl;
}

int main() {
    vector<string> questions;
    vector<string> answers;
    
    questions = getQuestions();
    answerQuestion(questions, answers);
    saveQuestionsAndAnswers(questions, answers);
    
    return 0;
}
