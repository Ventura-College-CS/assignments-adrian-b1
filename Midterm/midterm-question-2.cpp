#include <iostream>
#include <queue>
#include "Student.hpp"
#include <string>

using namespace std;
//To change the order of the Queue, just comment out the StudentCompare class and use one of the other ones
class StudentCompareScorDesc
{
    public:
        int operator()(Student &lhs, Student &rhs)
        {
            double lhssum = 0.0, rhssum = 0.0;
            for (int i=0;i<3;i++)
            {
                lhssum += *(lhs.getScores()+i);
                rhssum += *(rhs.getScores()+i);
            }
            return lhssum < rhssum;
        }
};
//*****Put Students in Descending ID Order:*****
class StudentCompareIdDesc
{
    public:
        int operator()(Student &lhs, Student &rhs)
        {
            int lhsid = 0, rhsid = 0;
            lhsid=lhs.getID();
            rhsid=rhs.getID();
            return lhsid < rhsid;
        }
};
//*****Put Students in Alphabetical Order:*****
class StudentCompareNameAsc
{
    public:
        int operator()(Student &lhs, Student &rhs)
        {
            string lhsname = "A", rhsname = "A";
            lhsname = lhs.getName();
            rhsname = rhs.getName();
            return lhsname > rhsname;
        }
};

int main()
{
    double g1[3]={95.0, 99.5, 90.0};
    double g2[3]={77.4, 55.6, 84.2};
    double g3[3]={78.4, 81.4, 92.0};
    double g4[3]={88.1, 23.5, 46.0};
    double g5[3]={90.2, 80.1, 70.0};
    Student s1 (100, "John", g1);
    Student s2 (101, "Ben", g2);
    Student s3 (102, "Allie", g3);
    Student s4 (103, "Caleb", g4);
    Student s5 (104, "Miles", g5);
    int select=0;
    cout<<"Please select a sorting method from the following options:"<<endl;
    cout<<"1: Descending by Scores"<<endl<<"2: Descending by ID"<<endl<<"3: Alphabetical"<<endl;
    while(select!=1 && select!=2 && select!=3)
    {
        cin>>select;
        if(select!=1&&select!=2&&select!=3)
        {
            cout<<"Your selection must be 1, 2, or 3. Please input your selection.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    switch(select){
        case 1:
        {
            priority_queue<Student, vector<Student>, StudentCompareScorDesc> pq;
            pq.push(s1); 
            pq.push(s2);
            pq.push(s3);
            pq.push(s4);
            pq.push(s5);
            while(!pq.empty())
            {
                Student temp = pq.top();
                cout<<"ID: "<<temp.getID()<<"\t";
                cout<<"Name: "<<temp.getName()<<"\t";
                for (int j=0;j<3;j++)
                {
                    cout<<"Score "<<j+1<<": "<<*(temp.getScores() + j)<<"\t";
                }
                cout<<endl;
                pq.pop();
            }
            break;
        }
        case 2:
        {
            priority_queue<Student, vector<Student>, StudentCompareIdDesc> pq;
            pq.push(s1); 
            pq.push(s2);
            pq.push(s3);
            pq.push(s4);
            pq.push(s5);
            while(!pq.empty())
            {
                Student temp = pq.top();
                cout<<"ID: "<<temp.getID()<<"\t";
                cout<<"Name: "<<temp.getName()<<"\t";
                for (int j=0;j<3;j++)
                {
                    cout<<"Score "<<j+1<<": "<<*(temp.getScores() + j)<<"\t";
                }
                cout<<endl;
                pq.pop();
            }
            break;
        }
        case 3:
        {
            priority_queue<Student, vector<Student>, StudentCompareNameAsc> pq;
            pq.push(s1); 
            pq.push(s2);
            pq.push(s3);
            pq.push(s4);
            pq.push(s5);
            while(!pq.empty())
            {
                Student temp = pq.top();
                cout<<"ID: "<<temp.getID()<<"\t";
                cout<<"Name: "<<temp.getName()<<"\t";
                for (int j=0;j<3;j++)
                {
                    cout<<"Score "<<j+1<<": "<<*(temp.getScores() + j)<<"\t";
                }
                cout<<endl;
                pq.pop();
            }
            break;
        }
        default:
        cout<<"Input not recognized."<<endl;
    }
}