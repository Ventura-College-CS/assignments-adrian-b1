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
        Course()
        {
            setID(0);
            setName("course");
            setCred(0);
        }
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
            cred=courseCred;
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
};

int main()
{
    ifstream ifs;
    Course array[10];
    int tempid, tempcred;
    string tempname;
    Course temp;

    ifs.open("courses.txt");
    if ( ifs.fail())
    {
        cerr << "File open error\n";
        exit(0);
    }
	for(int i=0;i<10; i++)
    {
        ifs >> tempid >> tempname >> tempcred;
        array[i].setID(tempid);
        array[i].setName(tempname);
        array[i].setCred(tempcred);
		if ( ifs.fail() )
		{
			cerr << "File Read Error\n";
			exit(0);
		}
    }

}