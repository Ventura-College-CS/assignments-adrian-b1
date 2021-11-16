#include <iostream>
#include  <vector>
#include "VectorQueue.hpp"

template <class T, int size>
VectorQueue<T, size>::VectorQueue(){
    queue.reserve(size);
}
template <class T, int size>
void VectorQueue<T, size>::enqueue(T el)
{
    if (!isFull())
	    queue.push_back(el);
    else
        cout<< "Queue is Full \n";
}
template <class T, int size>
T VectorQueue<T, size>::dequeue()
{
	T el = T();
	if(!isEmpty())
    {
        el = queue.front();
        queue.erase(queue.begin());
        return el;
    }
    else
    {
        cout << "Queue is empty\n";
    }
	return el;
}
template <class T, int size>
bool VectorQueue<T, size>::isEmpty()
{
	return queue.empty();
}
template <class T, int size>
bool VectorQueue<T, size>::isFull()
{
	if (queue.size() == size)
    return true;
    else
    return false;
}