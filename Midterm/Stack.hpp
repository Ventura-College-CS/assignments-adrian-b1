#ifndef STACK
#define STACK

#include <iostream>
#include <vector>
using namespace std;

template<class T>
class Stack
{
    private:
        vector<T> pool;
    public:
        Stack();
        void push(const T &el)
        {
            pool.push_back(el);
        }
        T pop()
        {
           T el = pool.back();
           pool.pop_back();
           return el; 
        }
        T &topEl() //get first element
        {
            return pool.front();
        }
        bool isEmpty()
        {
            return pool.empty();
        }
        int size() //get number of elements
        {
            return pool.size();
        }
}