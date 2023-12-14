
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import matplotlib.animation as mani



with open("testfile.txt", 'r') as file:
# extract info w/ either file.readlines() or through use of
# pandas dataframes into parameters below
# first line of output
    line1 = file.readline().split() # extract data on first line
    total_timestep = int(line1[1]) # total time
    rows = int(line1[3]) # dimensions of grid
    columns = int(line1[5])
   
    state = np.zeros((total_timestep, rows, columns))  # initialize grid (state)
    for ts in range(total_timestep): # iterates over every timestep
        for i in range(rows): # iterate over grid 
            for j in range(columns): 
                state[ts][i][j] = int(file.readline().split()[7]) # e.g. time: 0 row: 0 column: 0 cellstate: 1



#create plot
fig, ax = plt.subplots()

# show plot for every step
def step(timestep):
    ax.imshow(state[timestep], aspect="auto", cmap ="magma", interpolation="none") # can change interpolation (none for block like)

# creates animation over all timesteps
Cellular_Automata = mani.FuncAnimation(fig, step, frames=total_timestep, repeat=False, interval = 200)
plt.show()
plt.close()
