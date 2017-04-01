# algo3-tp1
Tp1 de algo3


## PROGRAMAS

Cada algoritmo para resolver un problema se encuentra en su propio .cpp
Hay makefiles para todo algoritmo, para simplificar

Todos (en teoria) leen por consola una serie de argumentos

```
make backtrack
make backtrack_naive
```

## DATOS (WIP): 

La generacion de datos esta hecha con algunas herramientas de python,
Donde se exportaran los resultados a un .csv

Todo esto esta muy verde, ver las clases de labo para darse una idea de como resolver


## INFORME:

La compilacion del informe se hace de foma automatica con un script que convierte del formato de jupyter
Esto es asi para poder insertar paquetes de latex que no se encuentran en el engine de jupyter
(En particular algorithms para el pseudocodigo)

La caratula entonces es inexistente por ser una compilacion automatica.
En la entrega final, puede hacerse alindarse editando a mano el archivo Informe.tex dentro de jupyter/

Comandos para compilar y ver el informe:

```
python makepdf.py

evince Informe.pdf

```
