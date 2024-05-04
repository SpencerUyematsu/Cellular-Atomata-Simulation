# Cellular Automata Simulation: Cell Infection

### University of California, Berkeley
### Chem 274B: Software Engineering Fundamentals for Molecular Sciences 

### Authors:  Spencer Uyematsu, Michael Soto, Kofi Mireku
### Date Created: December, 2023

This repository contains the implementation of a cellular automata simulation to simulate the spread of a virus through a population of cells.

## Compilation
To compile the code in this repository:
```
make all
```

## Running
You can view an example application of the source code in this repository in `Applications/Example/virus_simulation.cpp`.

To run and produce a visualization for this example code, run:
```
make run_application
```

The example application uses python to visualize the simulation. In order to produce this visualization, you need the following Python packages installed: Matplotlib, Seaborn, Pandas, NumPy.

You can also view an example of the analysis that can be conducted using this model in `Applications/Visualization/CASim.ipynb`

## LIST OF SUBDIRECTORIES IN THIS DIRECTORY:
- Applications/
- Bin/ 
- Lib/ 
- Include/
- Source/ 
- Tests/ 
- Utils/ 

## LIST OF FILES IN THIS DIRECTORY:
- README (this file - Each subdirectory has a respective README for further information)
- Makefile
- FinalProject-Assesment.pdf - File with Final Project Reflection
