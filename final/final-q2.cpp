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
int partition(Course array[], int first, int last)
{
    int pivot = array[last].getID();
    int i = -1;
    for (int j=0; j<last;j++)
    {
        if (array[j].getID<pivot)
            swap(array[++i], array[j]);
    }
    swap(array[i+1],array[last]);
    return i+1;
}
void qsort(Course array[], int first, int last)
{
    int pivot_idx;
    if (first>=last)
        return;
    pivot_idx = partition(array, first, last);
    qsort(array, first, pivot_idx-1);
    qsort(array, pivot_idx+1, last);
}
void printCourses(Course array[], int N)
{
    for(int i=0;i<N;i++)
    {
        cout<<"ID: "<<array[i].getID()<<"\t Name: "<<array[i].getName()<<"\t Credit: "<<array[i].getCred()<<endl;
    }
}
int main()
{
    ifstream ifs;
    Course array[10];
    int tempid, tempcred;
    string tempname;

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
    printCourses(array, 10);
    cout<<endl;
    cout<< "Now sorting..."<< endl << endl;
    qsort(array, 0, 9);
    printCourses(array, 10);
}