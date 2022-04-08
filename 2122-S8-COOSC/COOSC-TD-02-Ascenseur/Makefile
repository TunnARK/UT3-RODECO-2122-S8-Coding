#
# Makefile.c++
#
# Instructions:
#
# 1. Edit Makefile using vi or emacs:
#    a. rename target, if desired
#    b. add list of source files at SRCS = ...
# 2. % touch Makefile.dep
# 3. % make depend
# 4. % make
#

TARGET = cellule
CC = g++
CFLAGS = -Wall -g 

#Version materielle
INCLDIRS =

LIBS = 

SRCS = systeme.cpp environnement.cpp cabine.cpp panneau_exterieur.cpp ascenseur.cpp

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

