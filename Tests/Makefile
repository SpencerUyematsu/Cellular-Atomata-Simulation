# Chem 274B: Software Engineering Fundataions for
#            Molecular Sciences 
# University of California, Berkeley
#
# Creator: Group 14

# Directory Path: Week9/Source/Sort
# This creates executables for tests of sorting functions. 

# GNU C++ Compiler
CPP         = g++      

# compiler flags -O3 optimized version -c create a library object
CPPFLAGS    = -O3 -o

# The directory where Week 9's main library include files are stored.
INC_DIR = ../Include

# The directory where the include files for utilities are stored
UINC_DIR = ../Utils/Include

# The directory where Week 9's main library object files are stored
LIB_DIR     = ../Lib

# The directory where the library object files for utilities are stored
ULIB_DIR     = ../Utils/Lib

# Executable programs
BIN_DIR     = ../Bin

# The next line contains a list of executable object files 
# created by this Makefile.
SORT_EXECUTABLES =

test_setup: $(INC_DIR)/mycellularautomata.h
	$(CPP) $(CPPFLAGS) test_setup test_setup.cpp \
	-I$(INC_DIR) -L$(LIB_DIR) -lmycellularautomata

test_all: $(INC_DIR)/mycellularautomata.h
	$(CPP) $(CPPFLAGS) test_all test_all.cpp \
	-I$(INC_DIR) -L$(LIB_DIR) -lmycellularautomata
	./test_all
	rm test_all

CA:
	cd ../Source/Datatypes; make all