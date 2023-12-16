# Chem 274B: Software Engineering Fundamentals for
#            Molecular Sciences 
# University of California, Berkeley
# December 2023 - Final Project
#
# Creator:  Group 14
# Date Created: December 15, 2023
# 

# This is the global build Makefile from the root directory.
# This makefile can call other makefiles to build object files, 
# libraries or executables
# 
# See README file for information on the Utils, Source and Tests
# subdirectories used here

UTILS_DIR = Utils/           
SORC_DAT_DIR = Source/Datatypes
TST_DIR = Tests/
BIN_DIR = Bin/
APP_EX = Applications/Example
APP_BIN = Applications/Bin


all:
	cd $(UTILS_DIR); make all
	cd $(SORC_DAT_DIR); make all
	cd $(TST_DIR); make all
	cd $(APP_EX); make virus_simulation

run_application:
	cd Applications; make application

cleanall:	
	cd $(UTILS_DIR); make cleanall
	cd $(SORC_DAT_DIR); make cleanall
	cd $(TST_DIR); make cleanall
	cd $(BIN_DIR); make cleanall
	cd $(APP_BIN); make cleanall
