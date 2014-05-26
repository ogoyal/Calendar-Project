#Ojas Goyal
#Rohan Phadke

cal.out: appointment.o calendar.o day.o dayofweek.o time.o year.o linkedlist.o
	g++ -Wall -ansi -g -o cal.out appointment.o calendar.o day.o dayofweek.o time.o year.o linkedlist.o

appointment.o: appointment.cpp appointment.h time.h
	g++ -Wall -ansi -g -c appointment.cpp

calendar.o: calendar.cpp time.h appointment.h day.h year.h 
	g++ -Wall -ansi -g -c calendar.cpp

day.o: day.cpp day.h dayofweek.h 
	g++ -Wall -ansi -g -c day.cpp

dayofweek.o: dayofweek.cpp dayofweek.h 
	g++ -Wall -ansi -g -c dayofweek.cpp

time.o: time.cpp time.h 
	g++ -Wall -ansi -g -c time.cpp

year.o: year.cpp year.h day.h 
	g++ -Wall -ansi -g -c year.cpp

linkedlist.o: linkedlist.cpp linkedlist.h
	g++ -Wall -ansi -g -c linkedlist.cpp

clean:
	rm -f cal.out appointment.o calendar.o day.o dayofweek.o time.o year.o linkedlist.o 
