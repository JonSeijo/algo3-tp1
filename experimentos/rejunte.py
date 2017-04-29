# Como no quiero incluir todos los archivos de jupyter notebook,
# copipasteo aca las funciones y cosas que utilice

# ------------------------------------------------------------
#   Graficador creciente

import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np

datos_naive = pd.read_csv('../datos/naive/creciente.csv')
datos_naive.drop(datos_naive.columns[50], axis = 1,inplace=True) # Borro columna fea
#datos_naive.drop(15, inplace=True) # Borro n=16 para achicar grafico
datos_naive['mean'] = datos_naive.mean(axis = 1)
datos_naive['meanSeconds'] = datos_naive['mean'] / 1000000000
datos_naive



datos_poda = pd.read_csv('../datos/poda/creciente.csv')
datos_poda.drop(datos_poda.columns[50], axis = 1,inplace=True) # Borro columna fea
datos_poda['mean'] = datos_poda.mean(axis = 1)
datos_poda['meanSeconds'] = datos_poda['mean'] / 1000000000
datos_poda



%matplotlib inline
tiempos_naive = datos_naive['meanSeconds']
tiempos_poda = datos_poda['meanSeconds']

# 50 repes
# Naive: n = 15
# Poda: n = 40

plt.clf()
fig = plt.figure(figsize=(8,6))

plot_naive = tiempos_naive.plot(fontsize = 13)
plot_poda = tiempos_poda.plot()

fig.suptitle('Backtrack - Elementos crecientes', fontsize=20, position = (0.5, 1.05)) # Add the text/suptitle to figure
plot_naive.set_title('\n Tiempo medio entre 50 repeticiones de secuencias crecientes \n para diferentes tamaño de secuencias', fontsize = 15)
plot_naive.legend(['Naive', 'Poda'], fontsize = 14)
plot_naive.set_xlabel("Cantidad de elementos", size = 14)
plot_naive.set_ylabel("Segundos", size = 14)

plt.show()



#ESCALA LOGARITMICA
%matplotlib inline
tiempos_naive = datos_naive['meanSeconds']
tiempos_poda = datos_poda['meanSeconds']

# 50 repes
# Naive: n = 15
# Poda: n = 40

plt.clf()
fig = plt.figure(figsize=(8,6))
plot_naive = tiempos_naive.plot(fontsize = 13, logy = True)
plot_poda = tiempos_poda.plot(logy = True)

fig.suptitle('Backtrack: Elementos crecientes - ESCALA LOGARITMICA\n ', fontsize=20, position=(0.5, 1.05)) # Add the text/suptitle to figure
plot_naive.set_title('\n Tiempo medio entre 50 repeticiones de secuencias crecientes \n para diferentes tamaño de secuencias', fontsize = 15)
plot_naive.legend(['Naive', 'Poda'], fontsize = 14)
plot_naive.set_xlabel("Cantidad de elementos", size = 14)
plot_naive.set_ylabel("Segundos", size = 14)

plt.show()






datos_topdown = pd.read_csv('../datos/topdown/creciente.csv')
datos_topdown.drop(datos_topdown.columns[50], axis = 1,inplace=True) # Borro columna fea
datos_topdown['mean'] = datos_topdown.mean(axis = 1)
datos_topdown['meanSeconds'] = datos_topdown['mean'] / 1000000000
datos_topdown






datos_bottomup = pd.read_csv('../datos/bottomup/creciente.csv')
datos_bottomup.drop(datos_bottomup.columns[50], axis = 1,inplace=True) # Borro columna fea
datos_bottomup['mean'] = datos_bottomup.mean(axis = 1)
datos_bottomup['meanSeconds'] = datos_bottomup['mean'] / 1000000000
datos_bottomup





%matplotlib inline
tiempos_topdown = datos_topdown['meanSeconds']
tiempos_bottomup = datos_bottomup['meanSeconds']

# Repes = 50
# TopDown: n = 130
# BottomUp: n = 150

plt.clf()
fig = plt.figure(figsize=(8,6))
plot_topdown = tiempos_topdown.plot()
tiempos_bottomup.plot()

fig.suptitle('DP - Elementos crecientes', fontsize=20, position = (0.5, 1.05)) # Add the text/suptitle to figure

plot_topdown.set_title('\n Tiempo medio entre 50 repeticiones de secuencias con elementos crecientes \n para diferentes tamaño de secuencias', fontsize = 15)
plot_topdown.legend(['TopDown', 'BottomUp'], fontsize = 14)
plot_topdown.set_xlabel("Cantidad de elementos", size = 14)
plot_topdown.set_ylabel("Segundos", size = 14)

plt.show()





#ESCALA LOGARITMICA
%matplotlib inline
tiempos_naive = datos_naive['meanSeconds']
tiempos_poda = datos_poda['meanSeconds'][:160]
tiempos_topdown = datos_topdown['meanSeconds']
tiempos_bottomup = datos_bottomup['meanSeconds']

# 50 repes
# Naive: n = 15
# Poda: n = 40

plt.clf()
fig = plt.figure(figsize=(8,6))
plot_naive = tiempos_naive.plot(fontsize = 13, logy = True)
plot_poda = tiempos_poda.plot(logy = True)
tiempos_topdown.plot()
tiempos_bottomup.plot()

fig.suptitle('Elementos crecientes - ESCALA LOGARITMICA\n ', fontsize=20, position=(0.5, 1.03)) # Add the text/suptitle to figure
plot_naive.set_title('\n Tiempo medio entre 50 repeticiones de secuencias crecientes \n para diferentes tamaños de secuencias', fontsize = 15)
plot_naive.legend(['Naive', 'Poda', 'TopDown', 'BottomUp'], fontsize = 14)
plot_naive.set_xlabel("Cantidad de elementos", size = 14)
plot_naive.set_ylabel("Segundos", size = 14)

plt.show()



# ------------------------------------------------------------
# Graficador random


import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np



datos_naive_random = pd.read_csv('../datos/naive/random.csv')
datos_naive_random.drop(datos_naive_random.columns[50], axis = 1,inplace=True) # Borro columna fea
datos_naive_random.drop(15, inplace=True) # Borro n=16 para achicar grafico
datos_naive_random['mean'] = datos_naive_random.mean(axis = 1)
datos_naive_random['meanSeconds'] = datos_naive_random['mean'] / 1000000000
datos_naive_random



datos_poda_random = pd.read_csv('../datos/poda/random.csv')
datos_poda_random.drop(datos_poda_random.columns[50], axis = 1,inplace=True) # Borro columna fea
datos_poda_random['mean'] = datos_poda_random.mean(axis = 1)
datos_poda_random['meanSeconds'] = datos_poda_random['mean'] / 1000000000
datos_poda_random


%matplotlib inline
tiempos_naive_random = datos_naive_random['meanSeconds']
tiempos_poda_random = datos_poda_random['meanSeconds']

# 50 repes
# Naive: n = 15
# Poda: n = 40

plt.clf()
fig = plt.figure(figsize=(8,6))
plot_naive = tiempos_naive_random.plot(fontsize = 13)
plot_poda = tiempos_poda_random.plot()

fig.suptitle('Backtrack - Random', fontsize=20, position=(0.5, 1.02)) # Add the text/suptitle to figure
plot_naive.set_title('\n Tiempo medio entre 50 repeticiones de secuencias aleatorias \n para diferentes tamaño de secuencias', fontsize = 15)
plot_naive.legend(['Naive', 'Poda'], fontsize = 14)
plot_naive.set_xlabel("Cantidad de elementos", size = 14)
plot_naive.set_ylabel("Segundos", size = 14)

plt.show()



datos_topdown_random = pd.read_csv('../datos/topdown/random.csv')
datos_topdown_random.drop(datos_topdown_random.columns[50], axis = 1,inplace=True) # Borro columna fea
datos_topdown_random['mean'] = datos_topdown_random.mean(axis = 1)
datos_topdown_random['meanSeconds'] = datos_topdown_random['mean'] / 1000000000

datos_topdown_random




datos_bottomup_random = pd.read_csv('../datos/bottomup/random.csv')
datos_bottomup_random.drop(datos_bottomup_random.columns[50], axis = 1,inplace=True) # Borro columna fea
datos_bottomup_random['mean'] = datos_bottomup_random.mean(axis = 1)
datos_bottomup_random['meanSeconds'] = datos_bottomup_random['mean'] / 1000000000
datos_bottomup_random



%matplotlib inline
tiempos_topdown_random = datos_topdown_random['meanSeconds']
tiempos_bottomup_random = datos_bottomup_random['meanSeconds']

# Repes = 50
# TopDown: n = 130
# BottomUp: n = 150
plt.clf()

fig = plt.figure(figsize=(9,7))

ax_td = tiempos_topdown_random.plot(fontsize = 13)
ax_bu = tiempos_bottomup_random.plot()

fig.suptitle('DP - Random', fontsize=20, position=(0.5, 1.00)) # Add the text/suptitle to figure
ax_td.set_title('\n Tiempo medio entre 50 repeticiones de secuencias aleatorias \n para diferentes tamaño de secuencias', fontsize = 15)
ax_td.legend(['TopDown', 'BottomUp'], fontsize = 14)
ax_td.set_xlabel("Cantidad de elementos", size = 14)
ax_td.set_ylabel("Segundos", size = 14)

plt.show()




%matplotlib inline
tiempos_topdown_random = datos_topdown_random['meanSeconds'][:20]
tiempos_bottomup_random = datos_bottomup_random['meanSeconds'][:20]

# Repes = 50
# TopDown: n = 130
# BottomUp: n = 150
plt.clf()

fig = plt.figure(figsize=(9,7))

ax_td = tiempos_topdown_random.plot(fontsize = 13)
ax_bu = tiempos_bottomup_random.plot()

fig.suptitle('DP - Random', fontsize=20, position=(0.5, 1.00)) # Add the text/suptitle to figure
ax_td.set_title('\n Tiempo medio entre 50 repeticiones de secuencias aleatorias \n para diferentes tamaño de secuencias', fontsize = 15)
ax_td.legend(['TopDown', 'BottomUp'], fontsize = 14)
ax_td.set_xlabel("Cantidad de elementos", size = 14)
ax_td.set_ylabel("Segundos", size = 14)

plt.show()




%matplotlib inline
tiempos_topdown_random = datos_topdown_random['meanSeconds']
tiempos_bottomup_random = datos_bottomup_random['meanSeconds']

# Repes = 50
# TopDown: n = 130
# BottomUp: n = 150
plt.clf()

fig = plt.figure(figsize=(9,7))

ax = tiempos_naive_random.plot()
tiempos_poda_random.plot()
tiempos_bottomup_random.plot()
tiempos_topdown_random.plot(fontsize = 13)

fig.suptitle('Todos - Random', fontsize=20, position=(0.5, 1.01)) # Add the text/suptitle to figure
ax.set_title('\n Tiempo medio entre 50 repeticiones de secuencias aleatorias \n para diferentes tamaños de secuencias', fontsize = 15)
ax.legend(['Naive', 'Poda', 'BottomUp', 'TopDown'], fontsize = 14)
ax.set_xlabel("Cantidad de elementos", size = 14)
ax.set_ylabel("Segundos", size = 14)

plt.show()




# ------------------------------------------------------------
# Graficador iguales


import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np



datos_naive = pd.read_csv('../datos/naive/iguales.csv')
datos_naive.drop(datos_naive.columns[50], axis = 1,inplace=True) # Borro columna fea
#datos_naive_random.drop(15, inplace=True) # Borro n=16 para achicar grafico
datos_naive['mean'] = datos_naive.mean(axis = 1)
datos_naive['meanSeconds'] = datos_naive['mean'] / 1000000000
datos_naive




datos_poda = pd.read_csv('../datos/poda/iguales.csv')
datos_poda.drop(datos_poda.columns[50], axis = 1,inplace=True) # Borro columna fea
datos_poda['mean'] = datos_poda.mean(axis = 1)
datos_poda['meanSeconds'] = datos_poda['mean'] / 1000000000
datos_poda




%matplotlib inline
tiempos_naive = datos_naive['meanSeconds']
tiempos_poda = datos_poda['meanSeconds']

# 50 repes
# Naive: n = 15
# Poda: n = 40

plt.clf()
fig = plt.figure(figsize=(8,6))
plot_naive = tiempos_naive.plot()
plot_poda = tiempos_poda.plot()

fig.suptitle('Backtrack - Elementos iguales', fontsize=20, position = (0.5, 1.05)) # Add the text/suptitle to figure
plot_naive.set_title('\n Tiempo medio entre 50 repeticiones de secuencias iguales \n para diferentes tamaño de secuencias', fontsize = 15)
plot_naive.legend(['Naive', 'Poda'], fontsize = 14)
plot_naive.set_xlabel("Cantidad de elementos", size = 14)
plot_naive.set_ylabel("Segundos", size = 14)

plt.show()





#ESCALA LOGARITMICA

%matplotlib inline
tiempos_naive = datos_naive['meanSeconds']
tiempos_poda = datos_poda['meanSeconds']

# 50 repes
# Naive: n = 15
# Poda: n = 40

plt.clf()
fig = plt.figure(figsize=(8,6))
plot_naive = tiempos_naive.plot(fontsize = 13, logy = True)
plot_poda = tiempos_poda.plot(logy = True)

fig.suptitle('Backtrack: Elementos iguales - ESCALA LOGARITMICA\n ', fontsize=20, position=(0.5, 1.05)) # Add the text/suptitle to figure
plot_naive.set_title('\n Tiempo medio entre 50 repeticiones de secuencias iguales \n para diferentes tamaño de secuencias', fontsize = 15)
plot_naive.legend(['Naive', 'Poda'], fontsize = 14)
plot_naive.set_xlabel("Cantidad de elementos", size = 14)
plot_naive.set_ylabel("Segundos", size = 14)

plt.show()




datos_topdown = pd.read_csv('../datos/topdown/iguales.csv')
datos_topdown.drop(datos_topdown.columns[50], axis = 1,inplace=True) # Borro columna fea
datos_topdown['mean'] = datos_topdown.mean(axis = 1)
datos_topdown['meanSeconds'] = datos_topdown['mean'] / 1000000000
datos_topdown




datos_bottomup = pd.read_csv('../datos/bottomup/iguales.csv')
datos_bottomup.drop(datos_bottomup.columns[50], axis = 1,inplace=True) # Borro columna fea
datos_bottomup['mean'] = datos_bottomup.mean(axis = 1)
datos_bottomup['meanSeconds'] = datos_bottomup['mean'] / 1000000000
datos_bottomup





%matplotlib inline
tiempos_topdown = datos_topdown['meanSeconds']
tiempos_bottomup = datos_bottomup['meanSeconds']

# Repes = 50
# TopDown: n = 130
# BottomUp: n = 150

plt.clf()
fig = plt.figure(figsize=(8,6))
ax = tiempos_topdown.plot(fontsize = 13)
tiempos_bottomup.plot()

fig.suptitle('DP - Elementos iguales', fontsize=20, position = (0.5, 1.05)) # Add the text/suptitle to figure

ax.set_title('\n Tiempo medio entre 50 repeticiones de secuencias con elementos iguales \n para diferentes tamaño de secuencias', fontsize = 15)
ax.legend(['TopDown', 'BottomUp'], fontsize = 14)
ax.set_xlabel("Cantidad de elementos", size = 14)
ax.set_ylabel("Segundos", size = 14)


plt.show()





%matplotlib inline
tiempos_naive = datos_naive['meanSeconds']
tiempos_poda = datos_poda['meanSeconds'][:150]
tiempos_topdown = datos_topdown['meanSeconds']
tiempos_bottomup = datos_bottomup['meanSeconds']

# 50 repes
# Naive: n = 15
# Poda: n = 40

plt.clf()
fig = plt.figure(figsize=(8,6))
plot_naive = tiempos_naive.plot()
plot_poda = tiempos_poda.plot()
tiempos_topdown.plot(fontsize = 13)
tiempos_bottomup.plot()

fig.suptitle('Elementos iguales', fontsize=20, position = (0.5, 1.02)) # Add the text/suptitle to figure
plot_naive.set_title('\n Tiempo medio entre 50 repeticiones de secuencias iguales \n para diferentes tamaño de secuencias', fontsize = 15)
plot_naive.legend(['Naive', 'Poda', 'TopDown', 'BottomUp'], fontsize = 14)
plot_naive.set_xlabel("Cantidad de elementos", size = 14)
plot_naive.set_ylabel("Segundos", size = 14)

plt.show()





%matplotlib inline
tiempos_naive = datos_naive['meanSeconds']
tiempos_poda = datos_poda['meanSeconds'][:150]
tiempos_topdown = datos_topdown['meanSeconds']
tiempos_bottomup = datos_bottomup['meanSeconds']

# 50 repes
# Naive: n = 15
# Poda: n = 190

plt.clf()
fig = plt.figure(figsize=(8,6))
plot_naive = tiempos_naive.plot(logy = True)
plot_poda = tiempos_poda.plot()
tiempos_topdown.plot(fontsize = 13)
tiempos_bottomup.plot()

fig.suptitle('Elementos iguales - ESCALA LOGARITMICA', fontsize=20, position = (0.5, 1.03)) # Add the text/suptitle to figure
plot_naive.set_title('\n Tiempo medio entre 50 repeticiones de secuencias iguales \n para diferentes tamaños de secuencias', fontsize = 15)
plot_naive.legend(['Naive', 'Poda', 'TopDown', 'BottomUp'], fontsize = 14)
plot_naive.set_xlabel("Cantidad de elementos", size = 14)
plot_naive.set_ylabel("Segundos", size = 14)

plt.show()





