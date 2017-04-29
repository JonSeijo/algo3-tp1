# algo3-tp1
Tp1 de algo3

## NOTA:

Puede verse el informe compilado en informe/informe.pdf


## INFORME

Hecho con latex. Para compilar y ver:

```
python makepdf.py
```

Puede especificarse con el parametro ```--p=5``` el numero de pagina en la cual el pdf se va a abrir. HIPER UTIL POSTA!!

Todos los archivos .tex del informe estan en /informe/

Puede verse una version ya compilada en informe/informe.pdf



## DATOS

La generacion de datos esta hecha con algunas herramientas de python,
Donde se exportaran los resultados a un .csv

Todo esto esta muy verde, ver las clases de labo para darse una idea de como resolver

La idea es que una vez tengo todos los datos en el .csv,
Automatizo los experimentos para que se corran de ese .csv, sea cuales sean.
En caso de modificar los algoritmos (ergo los datos) lo unico que tengo que hacer
es correr la herramienta graficadora una unica vez

```
python crearDatos.py -naive_random -naive_creciente ....
```

ver con -h para un listado con las muestras posibles.


## GRAFICOS

Creados con python usando pandas.
Originalmente los escribi para jupyter notebook, pero el codigo utilizado se encuentra en experimentos/rejunte.py


## PROGRAMAS

Cada algoritmo para resolver un problema se encuentra en su propio .cpp

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


Tambien pueden encontrarse los archivos listos para la entrega como ejX.cpp, donde X es el numero de ejercicio



# TODO


[X] Uso de argv como entrada

[X] Separacion de backtracking naive y con poda

[X] .cpp de backtracking no usen main

[X] Crear un archivo definiciones

[X] Crear un ejecutable para medir tiempos

[X] Crear un ejecutable para verificar soluciones

[X] Armar makefile

[X] Mejorar el algoritmo de bt poda haciendo que corte la solucion si tengo mas sinPintar que el minimo que consegui al momento (Tendria que tener una especie de minimo global por mas feo que suene, para no morir con el tema de los parametros)

[X] cpp de tiempos da los nanosegundos para cada algoritmo, dado una instancia

[X] Crear carpeta para csv

[X] Que ~tiempos~ crearDatos.py escriba archivos csv

[X] Crear script de python generador que ejecute ./tiempos

[X] Pensar como organizar los experimentos

[X] Que el script de python pueda generar instancias al azar de tamaño n

[X] Que el script de python pueda repetir la misma instancia r veces

[-] Hacer testeos mas complejos !

[X] Ver como analizar las complejidades (Es incorrecto hacer una comparacion tiempos/curvas)

[X] Armar introduccion/explicacion del problema

[X] Pensar mas ejemplos para agregar

[X] Agregar imagen a la caratula

[X] Hacer analisis de complejidades

[X] ¿Es posible que el backtracking de poda no sea exponencial en mejor caso? Analizar eso

[X] Resolver usando DP bottomup

[X] Resolver usando DP topdown

[X] Usar diferentes tablas para el topdown y el bottom up, para no pagar el costo de borrar una en la otra version

[X] Armar ejecutables de ejX para cumplir consigna de tp.
(Basicamente quiero poder hacer "make ej1" y "./ej1 [params]" )

[X] Cota superior del informe: 10 paginas
