
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import matplotlib.animation as mani


state = pd.read_csv("test_output.csv")
width = state.iloc[0,-2]
height = state.iloc[0,-1]

data = state.iloc[:,:-2]
state = data.values.reshape(-1,height,width)

#create plot
fig, ax = plt.subplots()

# show plot for every step
def step(timestep):
    ax.imshow(state[timestep], aspect="auto", cmap ="magma", interpolation="none") # can change interpolation (none for block like)

# creates animation over all timesteps
Cellular_Automata = mani.FuncAnimation(fig, step, frames= state.shape[0], repeat=True, interval = 1000)
plt.show()
plt.close()
