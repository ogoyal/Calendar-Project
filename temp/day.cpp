//Ojas Goyal
//Rohan Phadke

#include <iostream>
#include <iomanip>
#include "day.h"
#include "dayofweek.h"

using namespace std;

Day::Day(): apptCount(0)
{
}

Day::Day(short mo, short d): day(d),month(mo), apptCount(0)
{

}

Day::Day(const Day& d): day(d.day), month(d.month), apptCount(d.apptCount)
{
	for (size_t i = 0; i < 8; i++)
	{
		appts[i] = new Appointment (*d.appts[i]);
	}
}

Day::~Day()
{
  for(int j = 0; j < apptCount; j++)
    delete  appts[j];
}

int Day::compareDate(short mo, short d) const
{
  if(month == mo)
    return day - d;
  else
    return month - mo;
} 

short Day::getMonth() const
{
  return month;
}

short Day::getDay() const
{
  return day;
}

ostream& operator<< (ostream & os, const Day &d)
{
  DayOfWeek dayOfWeek(d.month, d.day);
  dayOfWeek.read();
  os << dayOfWeek;
  return os;
}

bool Day::operator< (const Day& rhs) const
{
	return (month < rhs.month) || ((month == rhs.month) && ( day < rhs.day));
}

bool Day::operator== (const Day& rhs)
{
	return ((this->month == rhs.month) && (this->day ==rhs.day) && (this->apptCount == rhs.apptCount) && (this->appts == rhs.appts));
}

Day& Day::operator= (const Day &d)
{
  if(this == &d)
    return *this;

  for(int j = 0; j < apptCount; j++)
    delete  appts[j];

  day = d.day;
  month = d.month;
  apptCount = d.apptCount;

  for(int i = 0; i < apptCount; i++)
  {
    appts[i] = new Appointment();
    *appts[i] = *d.appts[i];
  }

  return *this;
}

istream& operator>> (istream & is, Day &d)
{
  d.appts[0] = new Appointment();
  is >> *(d.appts[0]);
  d.apptCount = 1;
  return is;
}

Day& Day::operator+= (const Day & d)
{
  for(int i = 0; i < d.apptCount; i++)
  {
    appts[apptCount] = new Appointment();
    *appts[apptCount] = *(d.appts[i]);
    apptCount++;
  }

  return *this;
}

void Day::printAppts() const
{
  for(int j = 0; j < apptCount; j++)
    cout << *appts[j];
}

void Day::printSubject(const char *s, bool &found) const
{
  for(int j = 0; j < apptCount; j++)
    if(*appts[j] == Appointment(s))
    {
      if(!found)
        cout << "Date                           Start End   Subject         "
          << "Location\n";

      cout << *this;
      cout << *appts[j];
      found = true;
    }
}

void Day::read()
{
  appts[apptCount] = new Appointment;
  appts[apptCount++]->read();
}

void Day::reset(short mo, short d)
{
  month = mo;
  day = d;

  for(int j = 0; j < apptCount; j++)
    delete appts[j];

  apptCount = 0;
}