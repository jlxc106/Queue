//Queue.cpp
//Written by Jay Lim
//Sept. 17, 2016

#include <stdio.h>
#include <iostream>

using namespace std;

template <typename T> struct node
{
	node<T> *forward;
	node<T> *backward;
	T nodeData;
};

//Queue is a First In First Out Data Structure.
template <typename T> class Queue
{
public:

	node<T> *Back;
	node<T> *Front;
	node<T> *temp;
	int Q_size;

//default constructor
	Queue()
	{
		Q_size = 0;
		Back = NULL;
		Front = NULL;
	}
//destructor
	~Queue()
	{
		while(Q_size >0)
		{
			pop_front();
		}
	}

/*
Method: empty
Parameters: void
Description: returns true if queue is  empty. False otherwise.
Returns: boolean. Returns true if empty
*/
	bool empty()
	{
		if(Q_size ==0)
			return true;
		else return false;
	}

/*
Method: size
Parameters: void
Description: returns the size of queue
Returns: integer
*/
	int size()
	{
		return Q_size;
	}

/*
Method: front
Parameters: void
Description: returns a pointer to the node at the top of the Queue
Returns: pointer to a node
*/
	node<T> *front()
	{
		return Front;
	}

/*
Method: back
Parameters: void
Description: returns a pointer to the node at the bottom of the Queue
Returns: pointer to a node
*/
	node<T> *back(){
		return Back;
	}

/*
Method: push_back
Parameters:template key
Description: adds a node toward the back of the Queue & assigns it the pointer Back
Returns: void
*/
	void push_back(T key){
		if(Q_size==0)
		{
			//corner case: first node in Queue
			Front = new node<T>;
			Back = new node<T>;
			Back -> nodeData = key;
			Back -> backward = NULL;
			Back -> forward = NULL;
			Front = Back;
			Q_size++;
		}
		else
		{
			Back -> backward = new node <T>;
			temp = Back -> backward;
			temp -> nodeData = key;
			temp -> forward = Back;
			temp -> backward = NULL;
			Back = temp;
			Q_size++;
		}
	}

/*
Method: pop_front
Parameters: void
Description: removes a node from the top of the Queue & assigns it the pointer Front
Returms: void
*/
	void pop_front()
	{
		if(Q_size > 0)
		{
			if(Q_size > 1)
			{
			temp = Front;
			Front = Front -> backward;
			temp -> backward = NULL;
			//cout << "pop " << temp -> nodeData << endl;
			delete temp;
			temp = NULL;
			Front -> forward = NULL;
			}
			else 
			{
				//corner case: last node in Queue
				delete Front;
				Front = NULL;
				Back = NULL;
			}
			Q_size--;
		}
	}
};

int main()
{
	Queue<int> QQ;
	for(int i =0; i < 20 ; i++)
	{
	QQ.push_back(i);
	}
	QQ.pop_front();

}

