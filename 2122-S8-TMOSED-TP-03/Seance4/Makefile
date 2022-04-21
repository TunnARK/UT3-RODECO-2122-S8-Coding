# Project: moulinetteRdP
# Makefile created by Dev-C++ 4.9.9.2
CC   = gcc -Wall -g
BIN = moulinetteRdP.exe
OBJ  = main.o strsplit.o NettoyerLaChaine.o types.o CreerStructure.o CreerUneTransition.o CreerUnePlace.o CreerUnArc.o GenererLog.o GenerateurCode.o GenererPlaces.o GenererBlocG.o
LINKOBJ  = main.o strsplit.o NettoyerLaChaine.o types.o CreerStructure.o CreerUneTransition.o CreerUnePlace.o CreerUnArc.o GenererLog.o GenerateurCode.o GenererPlaces.o GenererBlocG.o
RM = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before moulinetteRdP.exe all-after


clean: clean-custom
	${RM}  $(BIN)

$(BIN): $(OBJ)
	$(CC) $(LINKOBJ) -o "moulinetteRdP.exe"

main.o: main.c
	$(CC) -c main.c -o main.o
# strsplit.o: strsplit.c
#	$(CC) -c strsplit.c -o strsplit.o
# NettoyerLaChaine.o: NettoyerLaChaine.c
#	$(CC) -c NettoyerLaChaine.c -o NettoyerLaChaine.o
types.o: types.c
	$(CC) -c types.c -o types.o
# CreerStructure.o: CreerStructure.c
#	$(CC) -c CreerStructure.c -o CreerStructure.o
# CreerUneTransition.o: CreerUneTransition.c
#	$(CC) -c CreerUneTransition.c -o CreerUneTransition.o
# CreerUnePlace.o: CreerUnePlace.c
#	$(CC) -c CreerUnePlace.c -o CreerUnePlace.o
# CreerUnArc.o: CreerUnArc.c
#	$(CC) -c CreerUnArc.c -o CreerUnArc.o
GenerateurCode.o: GenerateurCode.c
	$(CC) -c GenererLog.c
	$(CC) -c GenerateurCode.c -o GenerateurCode.o
	GenererLog.o: GenererLog.c
# GenererPlaces.o: GenererPlaces.c
#	$(CC) -c GenererPlaces.c -o GenererPlaces.o
# GenererBlocG.o: GenererBlocG.c
#	$(CC) -c GenererBlocG.c -o GenererBlocG.o
