import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np

datos_naive_random = pd.read_csv('datos/naive/random.csv')
datos_naive_random['mean'] = datos_naive_random.mean(axis = 1)
datos_naive_random.head()