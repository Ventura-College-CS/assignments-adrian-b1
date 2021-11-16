#include "VectorQueue.hpp"
#include "VectorQueue.cpp"
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

const int MAX_LEN = 20;
const int NUM_SCORES = 3;
const int SIZE = 10;
struct Students
{
	int sid;
	char sname[MAX_LEN];
	double scores[NUM_SCORES];
};

int main()
{
    //1. create queue and enqueue 10 random int values
    VectorQueue<int, SIZE> q;
    for (int i=0; i<SIZE; i++)
    {
        int n;
        n = rand() % 100;
        q.enqueue(n);
    }
    //5. call enqueue when q is full  
    q.enqueue(27);
    //2. call dequeue and print all values
    for (int i=0; i<SIZE; i++)
    {
        cout << q.dequeue() << endl;
    }
    //6. call dequeue when q is empty
    q.dequeue();
    //3. create students queue
    VectorQueue<Students, 10> sq;
    //4. call enqueue and dequeue functions
    Students s;
    ifstream ifs;
    ifs.open("students.txt");
    if ( ifs.fail())
    {
        cerr << "File open error\n";
        exit(0);
    }
	for(int i=0;i<SIZE; i++)
    {
        ifs >> s.sid >> s.sname;
        for(int j=0; j<NUM_SCORES; j++)
			ifs >> s.scores[j] ;
		if ( ifs.fail() )
		{
			cerr << "File Read Error\n";
			exit(0);
		}
        sq.enqueue(s);
    }
    for(int i=0;i<SIZE;i++)
    {
        s=sq.dequeue();
        cout << "Student ID: " << s.sid << endl;
		cout << "Student Name: " << s.sname << endl;
		cout << "Student Scores: " << endl;
		for (int j = 0; j < NUM_SCORES; j++)
			cout << s.scores[j] << "\t";
        cout<<endl;
    }
    return 0;
}