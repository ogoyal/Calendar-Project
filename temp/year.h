//Ojas Goyal
//Rohan Phadke

#ifndef yearH
#define yearH

#include "day.h"
#include "linkedlist.h"

class Year
{
  int count;
  //int size;
  LinkedList *dayList;
  
public:
  Year();
  void addDate(int month, int day);
  int findDate(int month, int day) const;
  Year& operator+= (const Day &d);
  Year& operator-= (const Day&);
  void read();
  void searchDate(int month, int day) const;
  void searchSubject(const char *s) const;
};

#endif