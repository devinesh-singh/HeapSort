#include "PriorityQueue.h"
#include <iostream>

using namespace std;

PriorityQueue::PriorityQueue(int max_size)
{
	maxSize = max_size;
	currSize = 0;
	pQueue = new unsigned int[maxSize];
}

PriorityQueue::~PriorityQueue()
{
	delete[] pQueue;
}

void PriorityQueue::insert(unsigned int k)
{
	if (currSize == maxSize)
		cout << "PriorityQueue::insert called on full priority queue";
	pQueue[currSize++] = k;
	heapifyUp(currSize-1);
}

int PriorityQueue::removeMax()
{
	int maxElement;
	if (0 == currSize)
		cout << "PriorityQueue::removeMax called on an empty priority queue";
	maxElement = pQueue[0];
	pQueue[0] = pQueue[currSize-1];
	heapifyDown(0);
	currSize--;
	return maxElement;
}

void PriorityQueue::removeKey(unsigned int k)
{
	bool bFound = false;
	for (int i = 0; i < currSize; i++)
	{
		if (k == pQueue[i])
		{
			pQueue[i] = pQueue[currSize];
			bFound = true;
			break;
		}
	}

	if (false == bFound)
		cout << "PriorityQueue::removeKey key " << k << " not found";

	heapifyDown(0);
	currSize--;
}

void PriorityQueue::change(unsigned int k, unsigned int newK)
{
	bool bFound = false;
	for (int i = 0; i < currSize; i++)
	{
		if (k == pQueue[i])
		{
			pQueue[i] = newK;
			bFound = true;
			break;
		}
	}

	if (false == bFound)
		cout << "PriorityQueue::change key " << k << " not found";

	heapifyDown(0);	
}

void PriorityQueue::heapifyUp(int i)
{
	if (pQueue[i] > pQueue[parent(i)])
	{
		swap(pQueue[i], pQueue[parent(i)]);
		heapifyUp(parent(i));
	}
}

void PriorityQueue::heapifyDown(int i)
{
	int leftChild = left(i);
	int rightChild = right(i);

	int temp = i;

	if (leftChild<currSize && pQueue[leftChild] > pQueue[i])
		temp = leftChild;

	if (rightChild<currSize && pQueue[rightChild] > pQueue[temp])
		temp = rightChild;

	if (i != temp)
	{
		swap(pQueue[i], pQueue[temp]);
		heapifyDown(temp);	
	}
}

int PriorityQueue::parent(int i)
{
	return (i - 1) / 2;
}

int PriorityQueue::left(int i)
{
	return (2*i)+1;
}

int PriorityQueue::right(int i)
{
	return (2*i)+2;
}

void PriorityQueue::swap(unsigned int &num1, unsigned int &num2)
{
	unsigned int temp = num1;
	num1 = num2;
	num2 = temp;
}