# Chem 274B: Software Engineering Fundamentals for
#            Molecular Sciences 
# University of California, Berkeley
#
# Creator:  Group 14
# Date Created: December 15, 2023
#
# This is a global makefile, which means that make commands
# at this level will make calls to other make files in its
# subdirectories.  
#
# Targets in this Makefile:
#	all: makes all linkable object files from C++ programs in
#        CHEM274B_FINALPROJECT/Utils/Lib/ and 
#		 and builds libmymetrics.a
#     
#	cleanall: removes all linkable objects and libraries from 
#             CHEM274B_FINALPROJECT/Utils/Lib/

METRICS_DIR = Metrics/ 
RANGEN_DIR = Rangen/
LIB_DIR    = Lib/

all:
	cd $(METRICS_DIR); make all
	cd $(RANGEN_DIR); make all
	

cleanall:	
	cd $(METRICS_DIR); make cleanall
	cd $(RANGEN_DIR); make cleanall

