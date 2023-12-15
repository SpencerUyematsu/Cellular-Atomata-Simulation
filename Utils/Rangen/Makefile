
CPP = g++
CPPFLAGS = -O3 -c
INC_DIR = ../Include
LIB_DIR = ../Lib

RANDOM_OBJS = myrandomgenerator.o

MYRANDOM_LIB = libmyrandom.a

myrandomgenerator.o: $(INC_DIR)/myrandom.h
	$(CPP) $(CPPFLAGS) myrandomgenerator.cpp -I$(INC_DIR)

libmyrandom.a: $(RANDOM_OBJS)
	ar -ru $(MYRANDOM_LIB) $(RANDOM_OBJS)
	mv $(MYRANDOM_LIB) $(LIB_DIR)/.
	rm $(RANDOM_OBJS)

all: $(MYRANDOM_LIB)

cleanall:
	cd $(LIB_DIR); rm $(MYRANDOM_LIB)