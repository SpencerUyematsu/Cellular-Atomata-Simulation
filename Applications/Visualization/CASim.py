# Chem 274B: Software Engineering Fundamentals for
#            Molecular Sciences 
# Creator: Team 14 (Spencer Uyematsu, Michael Soto, Kofi Mireku)
# Date Created: 12/03/2023
# Last revisited: 12/15/2023
#
# Description:
#              This file contains a python script for performing the visualization animation for 
#               the automata simulation. It reads from the files generated in Applicatoins/Data and uses 
#                numpy and panda for efficient functionality

#
# mycellularautomata.h Contains the C++ Class declaration
#  

import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import matplotlib.animation as mani
import seaborn as sns


state = pd.read_csv("Data/virus_results.csv")

data = state
state = data.values.reshape(-1,50,50)

#create plot
fig, ax = plt.subplots()

# show plot for every step
def step(timestep):
    sns.heatmap(state[timestep], cbar=None)

# creates animation over all timesteps
Cellular_Automata = mani.FuncAnimation(fig, step, frames= state.shape[0], repeat=False, interval = 200)
plt.show()
plt.close()
