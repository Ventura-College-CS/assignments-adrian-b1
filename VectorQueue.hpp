#ifndef VECTORQUEUE_H
#define VECTORQUEUE_H

#include <iostream>
#include <vector>
using namespace std;

template <class T, int size=100>
class VectorQueue
{
private:
	vector<T> queue;

public:
	VectorQueue();
	void enqueue(T el);
	T dequeue();
	bool isEmpty();
	bool isFull();
};

#endif