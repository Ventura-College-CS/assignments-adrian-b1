#include <iostream>
#include <queue>
#include "Student.hpp"

using namespace std;

class StudentCompare
{
    public:
        int operator()(const Student &lhs, const Student &rhs)
        {
            double lhssum = 0.0, rhssum = 0.0;
            for (int i=0;i<3;i++)
            {
                lhssum += *(lhs.getScores()+i);
                rhssum += *(rhs.getScores()+i);
            }
            
        }
}

int main()
{
    double g1[3]={95.0, 99.5, 90.0};
    double g2[3]={77.4, 55.6, 84.2};
    double g3[3]={78.4, 81.4, 92.0};
    
    Student s1 (100, "John", g1);
    Student s2 (101, "Johnny", g2);
    Student s3 (102, "Johnson", g3);

    priority_queue<Student, vector<Student>, StudentCompare> pq;

}