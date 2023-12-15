# Chem 274B: Software Engineering Fundataions for
#            Molecular Sciences 
# University of California, Berkeley
#
# Creator: Group 14

# Directory Path: CHEM274B_FINALPROJECT/Source/Sort
# This creates executables for tests of sorting functions. 

# GNU C++ Compiler
CPP         = g++      

# compiler flags -O3 optimized version -c create a library object
CPPFLAGS    = -std=c++11 -O3 -o

# The directory where Final Project main library include files are stored.
INC_DIR = ../Include

# The directory where the include files for utilities are stored
UINC_DIR = ../Utils/Include

# The directory where Final Project main library object files are stored
LIB_DIR     = ../Lib

# The directory where the library object files for utilities are stored
ULIB_DIR     = ../Utils/Lib

# Executable programs
BIN_DIR     = ../Bin

# The next line contains a list of executable object files 
# created by this Makefile.
EXECUTABLES = test_setup test_boundaries 

test_setup: $(INC_DIR)/mycellularautomata.h
	$(CPP) $(CPPFLAGS) test_setup test_setup.cpp \
	-I$(INC_DIR) -I$(UINC_DIR) -L$(LIB_DIR) -lmycellularautomata \
	-L$(ULIB_DIR) -lmyrandom
	mv test_setup $(BIN_DIR)

test_boundaries: $(INC_DIR)/mycellularautomata.h
	$(CPP) $(CPPFLAGS) test_boundaries test_boundaries.cpp \
	-I$(INC_DIR) -I$(UINC_DIR) -L$(LIB_DIR) -lmycellularautomata \
	-L$(ULIB_DIR) -lmyrandom
	mv test_boundaries $(BIN_DIR)

test_rules: $(INC_DIR)/mycellularautomata.h
	$(CPP) $(CPPFLAGS) test_rules test_rules.cpp \
	-I$(INC_DIR) -I$(UINC_DIR) -L$(LIB_DIR) -lmycellularautomata \
	-L$(ULIB_DIR) -lmyrandom
# mv test_rules $(BIN_DIR)

test_all: $(INC_DIR)/mycellularautomata.h
	$(CPP) $(CPPFLAGS) test_all test_all.cpp \
	-I$(INC_DIR) -L$(LIB_DIR) -lmycellularautomata
	./test_all
	rm test_all

sim: $(INC_DIR)/mycellularautomata.h
	$(CPP) $(CPPFLAGS) test_simulation test_simulation.cpp \
	-I$(INC_DIR) -I$(UINC_DIR) -L$(LIB_DIR) -lmycellularautomata \
	-L$(ULIB_DIR) -lmyrandom
	./test_simulation
	rm test_simulation

test_timed_sim: $(INC_DIR)/mycellularautomata.h
	$(CPP) $(CPPFLAGS) test_timed_simulation test_timed_simulation.cpp \
	-I$(INC_DIR) -L$(LIB_DIR) -lmycellularautomata \
	-I$(UINC_DIR) -L$(ULIB_DIR) -lmyrandom -lmymetrics
	./test_timed_simulation
	rm test_timed_simulation

CA:
	cd ../Source/Datatypes; make all

all: $(EXECUTABLES)

cleanall: 
	cd $(BIN_DIR); rm $(EXECUTABLES)