# Chem 274B: Software Engineering Fundamentals for
# Molecular Sciences
# Creators:  Team 14 (Spencer Uyematsu, Michael Soto, Kofi Mireku)
# Date Created: 12/05/2023
# Directory Path: CHEM274B_FINALPROJECT/Source/Datatypes

# Description: This makefile creates a static library of all the object files in this 
#				directory. They support the cellular automaton application functionalites


# GNU C++ Compiler
CPP         = g++      # C++ Compuler

# compiler flags -g debug, -O2 optimized version -c create a library object
CPPFLAGS    = -O3 -c

# The directory where the include files needed to create the library objects are
INC_DIR     = ../../Include

# The directory where all object files are going to moved afer creation
LIB_DIR     = ../../Lib

UTIL_DIR = ../../Utils/Include

ULIB_DIR = ../../Utils/Lib

# DATA_OBJS contains the current list of object files created after
# compiling the C++ source files that declare and implement OO classes
DATA_OBJS   = cellular_automata.o simulation.o rules.o

# DATA_LIB is the name of object library file that will contain all
# DATA_OBJS files
DATA_LIB = libmycellularautomata.a 

# The following targets create a static library (a collection of
# linkable object files).
# use files to to build a library object file instead of moving to LIB_DIR.
cellular_automata.o: $(INC_DIR)/mycellularautomata.h
	$(CPP) $(CPPFLAGS) cellular_automata.cpp -I$(INC_DIR) -I$(UTIL_DIR) \
	-L$(ULIB_DIR) -lmyrandom

rules.o: $(INC_DIR)/mycellularautomata.h
	$(CPP) $(CPPFLAGS) rules.cpp -I$(INC_DIR) -I$(UTIL_DIR) \
	-L$(ULIB_DIR) -lmyrandom

simulation.o: $(INC_DIR)/mycellularautomata.h
	$(CPP) $(CPPFLAGS) simulation.cpp -I$(INC_DIR) -I$(UTIL_DIR) \
	-L$(ULIB_DIR) -lmyrandom

# We use the Linux command 'ar' to create the library by archiving previously created object files
# (here we are archiving in the library all the DATA_OBJS listed
# above). After all the object files in DATA_OBJS have been archived
# in the library object file, they can be removed.
libmycellularautomata.a: $(DATA_OBJS)
	ar ru $(DATA_LIB) $(DATA_OBJS) 
	mv $(DATA_LIB) $(LIB_DIR)
	rm $(DATA_OBJS)

# creates static library by running all .o targets
all: $(DATA_LIB)

# removes library object file from ../../library
cleanall:
	cd $(LIB_DIR); rm $(DATA_LIB)