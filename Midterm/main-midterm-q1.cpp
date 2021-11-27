#include <iostream>
#include <string>
#include "Student.hpp"
#include "Stack.hpp"

using namespace std;

int main()
{
Stack<Student> students;
double g1[3]={95.0, 99.5, 90.0};
double g2[3]={78.4, 81.4, 92.0};
double g3[3]={77.4, 55.6, 84,2};
double g4[3]={88.1, 23.5, 46.0};
double g5[3]={90.2, 80.1, 70.0};
Student s1 (100, "John", g1);
Student s2 (101, "Johnny", g2);
Student s3 (102, "Johnson", g3);
Student s4 (103, "Johnathan", g4);
Student s5 (104, "Jon", g5);
students.push(s1);
students.push(s2);
students.push(s3);
students.push(s4);
students.push(s5);
}