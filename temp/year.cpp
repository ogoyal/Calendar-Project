//Ojas Goyal
//Rohan Phadke

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "year.h"
#include "day.h"

using namespace std;

Year::Year():count(0)
{
	dayList = new LinkedList();
}

void Year::addDate(int month, int day)
{
	Day NewDate(month, day);
	*dayList += NewDate;
	count++;
}

int Year::findDate(int month, int day) const
{
	Day searchDay(month, day);
	ListNode *sentinel = this->dayList->first;
	int index(0);

	while(sentinel != NULL)
	{
		if(sentinel->day.getMonth() == searchDay.getMonth() && sentinel->day.getDay() == searchDay.getDay())
		{
			return index;
		}
		index++;
		sentinel = sentinel->next;
	}

	return count;
}

Year& Year::operator+= (const Day &day)
{
	addDate(day.getMonth(), day.getDay());
	return *this;
}

Year& Year::operator-= (const Day& day)
{
	*this->dayList -= day;
	return *this;
}

void Year::read()
{
	char s[256];
	int month, day;

	ifstream inf("appts.csv");
	inf.getline(s, 256);
	while(inf.getline(s, 256))
	{
		month = atoi(strtok(s,"/"));
		day = atoi(strtok(NULL,"/"));
		strtok(NULL, ",");

		int pos = findDate(month, day);

		if(pos == count)
		{
			addDate(month, day);
			pos = findDate(month, day);
		}

		ListNode *sentinel = this->dayList->first;
		for (int i = 0; i < pos; i++)
		{
			sentinel = sentinel->next;
		}

		sentinel->day.read();
	}
	inf.close();
}

void Year::searchDate(int month, int day) const
{
	bool found = false;

	ListNode *sentinel = this->dayList->first;
	for (int i = 0; i < count; i++)
	{
		if(sentinel->day.compareDate(month,day)==0)
		{
			cout << "Start End   Subject         Location\n";
			sentinel->day.printAppts();
			found = true;
			break;
		}
		sentinel = sentinel->next;
	}
	if(!found)
	{
		cout << "There are no appointments for that date.\n" << endl;
	}
}

void Year::searchSubject(const char *s) const
{
	bool found = false;
	
	ListNode *sentinel = this->dayList->first;
	for (int i = 0; i < count; i++)
	{
		sentinel->day.printSubject(s, found);
		sentinel = sentinel->next;
	}
	if(!found)
	{
		cout << s << " was not found as a subject in the calendar.\n" << endl;
	}
}