#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student
{
    private:
        int sID;
        string sName;
        double scores[3];
    public:
    Student();
    Student(int i, string name, double *sc)
    {
        sID=i;
        name=sName;
        for(int i=0;i<3;i++)
            scores[i]= *(sc+i);
    }
    int getID()
    {
        return sID;
    }
    string getName()
    {
        return sName;
    }
    double * getScores()
    {
        double *ptr;
        ptr=scores;
        return *ptr;
    }
}