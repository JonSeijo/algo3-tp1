# algo3-tp1
Tp1 de algo3

## WORKFLOW (wip)

Aca un breve descripcion del workflow


## PROGRAMAS

Cada algoritmo para resolver un problema se encuentra en su propio .cpp
Todos leen por consola una serie de argumentos

Para ver solo la solucion del problema (para todos los algoritmos) compilar con
```
make solucion
```
y ejecutar con ./solucion

Esto esta bueno para poder chequear que todos los algoritmos devuelvan el mismo resultado para la misma entrada.
Es necesario hace un chequeo mas exhaustivo y revisando esto es la herramienta ideal.


Para tener los datos de tiempo para cada algoritmo, compilar usando
```
make tiempos
```
y ejecutar con ./tiempos


## DATOS (WIP): 

La generacion de datos esta hecha con algunas herramientas de python,
Donde se exportaran los resultados a un .csv

Todo esto esta muy verde, ver las clases de labo para darse una idea de como resolver

La idea es que una vez tengo todos los datos en el .csv,
Automatizo los experimentos para que se corran de ese .csv, sea cuales sean.
En caso de modificar los algoritmos (ergo los datos) lo unico que tengo que hacer 
es correr la herramienta graficadora una unica vez


## INFORME:

Para compilar y ver el informe (incluso desde el directorio principal)

```
python makepdf.py
```

Todos los archivos .tex del informe estan en /informe/


# TODO


[X] Uso de argv como entrada

[X] Separacion de backtracking naive y con poda

[X] .cpp de backtracking no usen main

[X] Crear un archivo definiciones

[X] Crear un ejecutable para medir tiempos

[X] Crear un ejecutable para verificar soluciones

[X] Armar makefile

[-] Mejorar el algoritmo de bt poda haciendo que corte la solucion si tengo mas sinPintar que el minimo que consegui al momento (Tendria que tener una especie de minimo global por mas feo que suene, para no morir con el tema de los parametros) 

[-] Hacer testeos mas complejos !

[-] Crear carpeta para csv

[-] Que tiempos escriba archivos csv

[-] Crear script de python generador que ejecute ./tiempos

[-] Pensar como organizar los experimentos

[-] Que el script de python pueda generar instancias al azar de tamaño n

[-] Que el script de python pueda repetir la misma instancia r veces

[-] Ver como analizar las complejidades (Es incorrecto hacer una comparacion tiempos/curvas)

[-] Armar introduccion/explicacion del problema

[-] Pensar mas ejemplos para agregar

[-] Agregar imagen a la caratula

[-] Hacer analisis de complejidades

[-] ¿Es posible que el backtracking de poda no sea exponencial en mejor caso? Analizar eso 

[-] Preguntar bien que significa el item 2)

[-] Resolver usando DP bottomup

[-] Resolver usando DP topdown
