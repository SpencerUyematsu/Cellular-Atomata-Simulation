# GNU C++ Compiler
CPP         = g++      

# compiler flags -O3 optimized version -c create a library object
CPPFLAGS    = -std=c++11 -O3 -o

# The directory where Final Project main library include files are stored.
INC_DIR = ../../Include

# The directory where the include files for utilities are stored
UINC_DIR = ../../Utils/Include

# The directory where Final Project main library object files are stored
LIB_DIR     = ../../Lib

# The directory where the library object files for utilities are stored
ULIB_DIR     = ../../Utils/Lib

# Executable programs
BIN_DIR     = ../Bin

virus_simulation: 
	$(CPP) $(CPPFLAGS) virus_simulation virus_simulation.cpp \
	-I$(INC_DIR) -I$(UINC_DIR) -L$(LIB_DIR) -lmycellularautomata \
	-L$(ULIB_DIR) -lmyrandom
