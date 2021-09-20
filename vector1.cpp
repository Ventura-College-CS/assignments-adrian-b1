#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(vector<int>);
int main ()
{
    vector<int> numbers = {10, 13, 5, 7, 25};
    vector<int>::iterator it;
    int new_number;
    int del_number;
    printVector(numbers);
    sort(numbers.begin(), numbers.end());
    printVector(numbers);
    cout << "Enter your number to insert: ";
    cin>>new_number;
    for(it=numbers.begin();it<numbers.end();it++)
    {
        if (*it > new_number)
            break;
    }
    numbers.insert(it, new_number);
    printVector(numbers);
    cout << "Which number would you like to delete?";
    cin >> del_number;
    for(it=numbers.begin();it<numbers.end();it++)
    {
        if(*it==del_number)
            break;
    }
    if(it == numbers.end())
        cout << "Deleting value not found.\n";
    else
        numbers.erase(it);
    printVector(numbers);
    
return 0;
}

void printVector(vector<int> vec)
{
    vector<int>::iterator it;
    for(it=vec.begin();it<vec.end();it++)
        cout<<*it<<"\t";
    cout<<endl;
}