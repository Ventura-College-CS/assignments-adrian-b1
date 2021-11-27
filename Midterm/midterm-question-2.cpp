#include <iostream>
#include <queue>
#include "Student.hpp"
#include <string>

using namespace std;
//To change the order of the Queue, just comment out the StudentCompare class and use one of the other ones
class StudentCompare //Descending score order
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
/*class StudentCompare
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
*/
//*****Put Students in Alphabetical Order:*****
/*class StudentCompare
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
*/
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
    priority_queue<Student, vector<Student>, StudentCompare> pq;
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
}