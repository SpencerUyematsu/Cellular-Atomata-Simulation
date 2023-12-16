# Chem 274B: Software Engineering Fundamentals for
# Molecular Sciences
# Creators:  Team 14 (Spencer Uyematsu, Michael Soto, Kofi Mireku)
# Date Created: 12/15/2023
# Directory Path: CHEM274B_FINALPROJECT/Source/Datatypes

# Description: 	This makefile runs the cellular automtata applications built from 
#				the general purpose library developed by Team 14


# Cellular automata application
APPLICATION = Visualization/CASim.py


# run 
application:
	cd Example; make virus_simulation; \
	./virus_simulation; mv virus_simulation ../Bin; \
	mv virus_results.csv ../Data; mv virus_simulation_stats.csv ../Data;
	python ${APPLICATION}


