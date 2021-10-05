#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int *fillupArray(int N);
void printArray(int *, int N);
void deleteArray(int *);

int main()
{
	const int N=10;
	int *ptr;

	ptr = fillupArray(N);
	printArray(ptr, N);
    deleteArray(ptr);
}

void deleteArray(int *ptr)
{
	delete ptr;
}
void printArray(int *ptr, int N)
{
	for(int i=0; i<N;i++)
		cout << *(ptr+i) << "\t";
	cout << endl;
}

int *fillupArray(int N)
{
	int *ptr;
	ptr = new int[N];

	srand(time(0));
	for(int i=0; i<N;i++)
	{
		*(ptr+i) = rand() % 100; 
	}
	return ptr;

}