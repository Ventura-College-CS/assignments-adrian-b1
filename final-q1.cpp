#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Course
{
    private:
        int id;
        string name;
        int cred;
    public:
        Course();
        Course(int courseid, string coursename, int coursecred)
        {
            id=courseid;
            name=coursename;
            cred=coursecred;
        }
        int getID()
        {
            return id;
        }
        string getName()
        {
            return name;
        }
        int getCred()
        {
            return cred;
        }
}