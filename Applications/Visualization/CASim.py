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
