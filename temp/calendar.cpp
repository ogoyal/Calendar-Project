//Ojas Goyal
//Rohan Phadke

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include "time.h"
#include "appointment.h"
#include "day.h"
#include "year.h"

using namespace std;

int getChoice()
{
	int choice;
	char s[80];

	do
	{
		cout << "Calendar Menu\n0. Done.\n1. Search for date.\n";
		cout << "2. Search for subject.\n3. Add an appointment.\n4. Remove a date.\nYour choice >> ";
		cin >> choice;

		if(choice < 0 || choice > 4)
			cout << "\nChoice must be between 0 and 4.\nPlease try again.\n\n";
	} while(choice < 0 || choice > 4);

	cin.getline(s, 80);
	return choice;
}

void getDate(short &month, short &day)
{
	char s[80], s2[80], *ptr;
	day = month = 0;

	do
	{
		cout << "\nPlease enter the month and day (mm/dd) >> ";
		cin.getline(s, 80);
		strcpy(s2, s);
		ptr = strtok(s2,"/");

		if(ptr)
		{
			month = atoi(ptr);
			ptr = strtok(NULL, ",");
			if(ptr)
				day = atoi(ptr);
		}

		if(month < 1 || month > 12 || day < 1 || day > 31)
			cout << s << " is not a valid date.\nPlease try again.\n\n";
	} while(month < 1 || month > 12 || day < 1 || day > 31);
}

void getSubject(char *s)
{
	cout << "\nPlease enter the subject >> ";
	cin.getline(s, 80);
}

int main()
{
	Year year;
	int choice;
	short month, day;
	char s[80];

	year.read();
	choice = getChoice();

	while(choice != 0)
	{

		if(choice == 1)
		{
			getDate(month, day);
			year.searchDate(month, day);	
		}

		else if(choice == 2)
		{			
			getSubject(s);
			year.searchSubject(s);
		}

		else if (choice == 3)
		{
			getDate(month, day);
			Day NewDate(month, day);
			cin >> NewDate;
			year += NewDate;		
		}

		else if (choice == 4)
		{
			getDate(month, day);
			Day NewDate(month, day);
			year -= NewDate;
		}

		choice = getChoice();
	}
	
	return 0;
}
