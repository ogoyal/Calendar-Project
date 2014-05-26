//Ojas Goyal
//Rohan Phadke

#ifndef ListH
#define ListH
#include "day.h"

class ListNode
{
	Day day;
	ListNode *next;
	friend class LinkedList;
	friend class Year;
};

class LinkedList 
{
private:
	friend class Year;
	ListNode *first;

public:
	LinkedList();
	~LinkedList();
	Day& operator[] (size_t);
	const Day& operator[] (size_t) const;
	LinkedList& operator+= (const Day&);
	LinkedList& operator-= (const Day&);
};

#endif