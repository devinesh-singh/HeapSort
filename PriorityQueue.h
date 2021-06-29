#pragma once

class PriorityQueue
{
public:
	PriorityQueue(int max_size);
	~PriorityQueue();
	void insert(unsigned int k);
	int removeMax();
	void removeKey(unsigned int k);
	void change(unsigned int k, unsigned int newK);
	void heapifyUp(int i);
	void heapifyDown(int i);
	int parent(int i);
	int left(int i);
	int right(int i);
	void swap(unsigned int &num1, unsigned int &num2);
private:
	int maxSize;
	int currSize;
	unsigned int *pQueue;
};

