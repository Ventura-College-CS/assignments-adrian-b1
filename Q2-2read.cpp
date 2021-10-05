#include <iostream>
#include <fstream>
using namespace std;

const int 	MAX_LEN = 20;
const int 	NUM_SCORES = 3;

struct Students {
	int 	sid;
	char 	sname[MAX_LEN];
	double 	scores[NUM_SCORES];
};

Students *makeStudents(int );
void printStudent(Students * const);
void avgCheck(Students * const, int);


int main()
{
	const int N = 10;
	Students *ptr;

	ptr = makeStudents(N);
	avgCheck(ptr, N);
}

Students *makeStudents(int N)
{
	ifstream ifs;
    Students    *ptr= new Students [N];

    ifs.open("students.bin");
    if ( ifs.fail())
    {
        cerr << "File open error\n";
        exit(0);
    }

	for(int i=0;i<N; i++)
    {   ifs.read( (char *)&*(ptr+i), sizeof*(ptr+i) );
		if ( ifs.fail() )
		{
			cerr << "File Read Error\n";
			exit(0);
		}
    }
	return ptr;
}

void printStudent(Students * const s){
        cout << " ID : " << s->sid << "\t";
        cout << " Name : " << s->sname << "\t";
        cout << " Score 1 : " << s->scores[0]<<"\t";
        cout << " Score 2 : " << s->scores[1]<<"\t";
        cout << " Score 3 : " << s->scores[2]<<endl;


}

void avgCheck(Students * const s, int N){
    const int   MIN_AVG = 85; //this is the minimum average to display student info
    for(int i=0; i<N-1;i++)
    {
        if( ((((s+i)->scores[0]+(s+i)->scores[1]+(s+i)->scores[2])/3)>85) )
            printStudent((s+i));
    }
}