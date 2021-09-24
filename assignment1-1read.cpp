#include <iostream>
#include <fstream>
using namespace std;
struct Student {
    int id;
    char sname[20];
    double score[2];
    double sum;
    double avg;
};

void printStudent(Student s){
    cout << " ID : " << s.id << endl;
    cout << " Name : " << s.sname << endl;
    cout << " Score 1 : " << s.score[0]<<endl;
    cout << " Score 2 : " << s.score[1]<<endl;
    cout << " Sum : " << s.sum<<endl;
    cout << " Average : " << s.avg <<endl;    
}

void findStudent(int idnum){
    ifstream ifs;
    Student s[10];
    int flag = 0;
    ifs.open("student.bin");
    if(ifs.fail())
    {
        cout << " Could not open the file \n";
        exit(0);
    }
    for(int i=0;i<10;i++)
    {
        ifs.read( (char *)&s[i], sizeof(s[i]));
        if(s[i].id==idnum)
        {
            printStudent(s[i]);
            flag = 1; 
        }
    }
    if(!flag)
    cout<< "Student not found.\n";
}

int main()
{
    ifstream ifs;
    Student s[10];
    int idsearch;
    ifs.open("student.bin");
    if(ifs.fail())
    {
        cout << " Could not open the file \n";
        exit(0);
    }

    for(int i=0;i<10;i++)
    {
        ifs.read( (char *)&s[i], sizeof(s[i]));
        printStudent(s[i]);
    }
    cout<< "Please enter a student ID to view a student's information: ";
    cin>>idsearch;
    findStudent(idsearch);
return 0;
}
