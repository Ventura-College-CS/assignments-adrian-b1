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
        void setID(int courseid)
        {
            id=courseid;
        }
        void setName(string coursename)
        {
            name=coursename;
        }
        void setCred(int courseCred)
        {
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

Course findCourse(Course * ptr, int first, int last, int targetID)
{
    int mid;
    Course ret;
    if (first>last)
        return -1;
    mid = (first + last ) / 2;
    if (targetID==*(ptr + mid).getID())
        return mid;
    if (targetID < *(ptr + mid).getID())
        ret = binarySearch(ptr, first, mid-1, targetID);
    else
        ret = binarySearch(ptr, mid + 1, last, targetID);
    return ret;
}

int main()
{
    ifstream ifs;
    Course *ptr= new Course [N];
}