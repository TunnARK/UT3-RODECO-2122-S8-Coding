#
# Makefile.c++
#
# Instructions:
#
# 1. Edit Makefile using vi or emacs:
#    a. rename target, if desired
#    b. add list of source files at SRCS = ...
# 2. % make depend
# 3. % make
#

TARGET = cellule
CC = g++
CFLAGS = -Wall -g 

#Version materielle
INCLDIRS =  -I/usr/include -I/usr/realtime/ -I/usr/realtime/include -O2 -I/usr/src/linux/include -Wall -Wstrict-prototypes -pipe -D__IN_RTAI__

LIBS = 

SRCS = robot++.cpp structure++.cpp  systeme.cpp main.cpp

OBJS = ${SRCS:.cpp=.o} 

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCLDIRS) -o $@ $(OBJS)

$(OBJS):
	$(CC) $(CFLAGS) $(INCLDIRS) -c $*.cpp

depend:
	$(CC) -MM $(SRCS) $(INCLDIRS) > Makefile.dep

clean:
	rm -f $(OBJS) core

veryclean: clean
	rm -f $(TARGET) a.out

include Makefile.dep

