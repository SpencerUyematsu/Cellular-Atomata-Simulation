# Chem 274B: Software Engineering Fundamentals for
#            Molecular Sciences 
# 
# Creator:  Group
# Date Created: December 15, 2023
# Date Updated: December 15, 2023
#
# Directory Path: Assignment4/Utils/Metrics
#
# This makefile creates an object file containing timing utility 
# functions. After compiling all source program files, it creates a
# metrics library (libmymetrics.a), which is relocated to 
# Week7/Utils/Lib after its successful creation.

# GNU C++ Compiler
CPP         = g++      

# compiler flags -g debug, -O3 optximized version -c create a library object file
CPPFLAGS    = -O3 -c    

# The directory where the include files needed to create the library objects are
INC_DIR = ../Include

# The directory where all object files are going to moved afer creation
LIB_DIR = ../Lib

# The next line contains the list of timing utility object files created 
# with this Makefile (i.e. they are the targets this makefile builds)
TIMING_OBJS = mychrontimes.o
METRICS_LIB = libmymetrics.a

mychrontimes.o: $(INC_DIR)/mytimings.h
	$(CPP) $(CPPFLAGS) mychrontimes.cpp -I$(INC_DIR)

$(METRICS_LIB): $(TIMING_OBJS)
	ar -ru $(METRICS_LIB) $(TIMING_OBJS) 
	mv $(METRICS_LIB) $(LIB_DIR)
	rm $(TIMING_OBJS)

all: $(METRICS_LIB)

cleanall:
	cd $(LIB_DIR); rm $(METRICS_LIB)

