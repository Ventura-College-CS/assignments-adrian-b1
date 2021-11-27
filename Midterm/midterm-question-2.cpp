#include <iostream>
#include <queue>
#include "Student.hpp"

using namespace std;

int main()
{
    double g1[3]={95.0, 99.5, 90.0};
    double g2[3]={78.4, 81.4, 92.0};
    double g3[3]={77.4, 55.6, 84.2};
    Student s1 (100, "John", g1);
    Student s2 (101, "Johnny", g2);
    Student s3 (102, "Johnson", g3);
}