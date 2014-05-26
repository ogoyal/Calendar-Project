//Ojas Goyal
//Rohan Phadke

#include <iostream>
#include <stdlib.h>
#include "linkedlist.h"

using namespace std;

LinkedList::LinkedList()
{
    first=NULL;
}

LinkedList::~LinkedList()
{
	if(first == NULL)
	{
		return; 
	}

	ListNode *now = first;

	while(now!=NULL)
	{
		ListNode *tmp = now->next;
		delete now;
		now = tmp;
	}
}

Day& LinkedList::operator[] (size_t index) 
{
	if(this->first == NULL)
	{
		cerr << "Invalid input";
		exit(1);
	}

	if(index == 0)
	{
		return this->first->day;
	}
	else
	{
		ListNode *nextNode = this->first;

		for(size_t i = 0; i < index; i++)
		{
			if(nextNode->next == NULL)
			{
				cerr << "Invalid input";
				exit(1);
			}
			nextNode = nextNode->next;
		}
		return nextNode->day;
	}
}

const Day& LinkedList::operator[] (size_t index) const
{
	if(this->first == NULL)
	{
		cerr << "Invalid input";
		exit(1);
	}

	if(index == 0)
	{
		return this->first->day;
	}
	else
	{
		ListNode *nextNode = this->first;

		for(size_t i = 0; i < index; i++)
		{
			if(nextNode->next == NULL)
			{
				cerr << "Invalid input";
				exit(1);
			}
			nextNode = nextNode->next;
		}
		return nextNode->day;
	}
}

LinkedList& LinkedList::operator+= (const Day& date)
{

	ListNode *addNode = new ListNode();
	addNode->day = date;
	addNode->next = NULL;

	if(this->first == NULL)
	{
		this->first = addNode;
		return *this;
	}

	if(date < this->first->day)
	{
		addNode->next = this->first;
		this->first = addNode;
		return *this;
	}

	ListNode *prev = this->first;
	ListNode *now = this->first->next;

	while (now != NULL)
	{
		if(date < now->day)
		{
			addNode->next = now;
			prev->next = addNode;
			return *this;
		}
		prev = prev->next;
		now = now->next;
	}

	prev->next = addNode;
	return *this;
}

LinkedList& LinkedList::operator-= (const Day& date)
{
	ListNode *remNode = new ListNode();
	remNode->day = date;
	remNode->next = NULL;

	if(this->first == NULL)
	{
		return *this;
	}

	if(this->first->day == date)
	{
		ListNode *tmp = this->first;
		this->first = this->first->next;

		delete tmp;
		return *this;
	}

	ListNode *prev = this->first;
	ListNode *now = this->first->next;

	while(now != NULL)
	{
		if(now->day == date)
		{
			prev->next = now->next;
			delete now;
			return *this;
		}

		prev = prev->next;
		now = now->next;
	}

	return *this;
}
