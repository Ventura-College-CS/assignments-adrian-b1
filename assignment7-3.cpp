#include    <iostream>
using namespace std;

int     binarySearch(int array[], int first, int last, int target)
{
	int mid, ret;
    if (first>last)
        return -1;
    mid = (first + last ) / 2;
    if (target==array[mid])
        return mid;
    if (target < array[mid])
        ret = binarySearch(array, first, mid-1, target);
    else
        ret = binarySearch(array, mid + 1, last, target);
    return ret;
}
int main()
{
    const int N= 10;
    int array[N] = {10, 15, 20, 25, 30, 35, 40, 45, 50, 55};
    int    target;

    cout << "Enter the number to find in this array : ";
    cin >> target;
    cout << "Found number at " << binarySearch(array, 0, N-1, target) << endl;;
}


