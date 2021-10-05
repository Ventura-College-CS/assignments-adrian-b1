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


int main()
{
	const int N = 10;
	Students *ptr;

	ptr = makeStudents(N);
}

Students *makeStudents(int N)
{
	ifstream ifs;
    ofstream ofs;
    Students    *ptr= new Students [N];

    ifs.open("students.txt");
     ofs.open("students.bin");
    if ( ifs.fail())
    {
        cerr << "File open error\n";
        exit(0);
    }

	for(int i=0;i<N; i++)
    {
        ifs >> (ptr+i)->sid >> (ptr+i)->sname;
        for(int j=0; j<NUM_SCORES; j++)
			ifs >> (ptr+i)->scores[j] ;
        ofs.write( (char *)&*(ptr+i), sizeof*(ptr+i) );
		if ( ifs.fail() )
		{
			cerr << "File Read Error\n";
			exit(0);
		}
    }
	return ptr;
}