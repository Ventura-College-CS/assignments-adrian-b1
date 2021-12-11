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

Course findCourse(Course array[], int first, int last, int targetID)
{
    int mid;
    Course ret;
    if (first>last)
        return -1;
    mid = (first + last ) / 2;
    if (targetID==array[mid].getID())
        return mid;
    if (targetID < array[mid].getID())
        ret = binarySearch(array, first, mid-1, targetID);
    else
        ret = binarySearch(array, mid + 1, last, targetID);
    return ret;
}

