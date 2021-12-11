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

Course findCourse(Course array[], int first, int last, int targetID)
{
    int mid;
    Course ret;
    if (first>last)
    {
    cout<<"Target not found"<<endl;
    return array[0];
    }
    mid = (first + last ) / 2;
    if (targetID==array[mid].getID())
        {cout << "Found at array[" << mid <<"]" <<endl;
        return array[mid];}
    if (targetID < array[mid].getID())
        ret = findCourse(array, first, mid-1, targetID);
    else
        ret = findCourse(array, mid + 1, last, targetID);
    return ret;
}

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
    
    for(int i=0; i<9;i++)
    {
        for(int j=i+1; j<10;j++)
        {
            if(array[i].getID()>array[j].getID())
            {
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
    temp=findCourse(array, 0,9, 13214);
    cout << temp.getID() << "  " << temp.getName() << "  " << temp.getCred();
}