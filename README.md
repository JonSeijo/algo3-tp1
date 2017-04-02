# algo3-tp1
Tp1 de algo3

## WORKFLOW (wip)

Aca un breve descripcion del workflow


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

La idea es que una vez tengo todos los datos en el .csv,
Automatizo los experimentos para que se corran de ese .csv, sea cuales sean.
En caso de modificar los algoritmos (ergo los datos) lo unico que tengo que hacer 
es correr la herramienta graficadora una unica vez


## INFORME:

Todos los archivos .tex del informe estan en /informe/

Para compilar el .tex:

```
pdflatex informe.tex
```

Para ejecutar:
```
evince informe.pdf
```

# TODO

|- Uso de argv como entrada
|- Separacion de backtracking naive y con poda
|- .cpp de backtracking no usen main
|- Crear un archivo definiciones
|- Crear un ejecutable para medir tiempos
|- Crear un ejecutable para verificar soluciones
|- Armar makefile
- Hacer testeos mas complejos !
- Crear carpeta para csv
- Que tiempos escriba archivos csv
- Crear script de python generador que ejecute ./tiempos
- Pensar como organizar los experimentos
- Que el script de python pueda generar instancias al azar de tamaño n
- Que el script de python pueda repetir la misma instancia r veces
- Ver como analizar las complejidades (Es incorrecto hacer una comparacion tiempos/curvas)
- Armar introduccion/explicacion del problema
- Pensar mas ejemplos para agregar
- Agregar imagen a la caratula
- Hacer analisis de complejidades
- ¿Es posible que el backtracking de poda no sea exponencial en mejor caso? Analizar eso 
- Preguntar bien que significa el item 2)
- Resolver usando DP bottomup
- Resolver usando DP topdown
