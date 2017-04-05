#encoding: utf-8

import argparse
import random
import subprocess
import time

from sys import argv
from subprocess import call

ejecutable = "./tiempos"

path_naive = "datos/naive/"
path_poda = "datos/poda/"

path_random_cercanos = "random_cercanos.csv"
path_random_lejanos = "random_lejanos.csv"

repes = 25
n_maximo = 15

def args_naive_lista_random(ejec, tam, tope):
    return [ejec, "naive", str(tam)] + [str(random.randrange(1, tope+1)) for _ in range(tam)]

def exp_naive_random(archivo, tope):
    with open(path_naive + archivo, 'w') as f:
        for tam in range(1, n_maximo+1):   # Instancias de tamaño n
            print("Instancias random de tamaño: " + str(tam))
            print("\nn:" + str(tam), file=f)
            for r in range(repes):   
                # Repito repes veces las pruebas con cada tamaño 
                # (instancias aleatorias cada vez) para ver mejor el caso promedio
                output = subprocess.check_output(args_naive_lista_random(ejecutable, tam, tope))
                print(str(output.decode()), file=f, end=""),

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument("-naive_todos", help="Todos los experimentos de naive", action='store_true')
    parser.add_argument("-naive_random_cercanos", help="Naive con listas random en rango 1-20", action='store_true')
    parser.add_argument("-naive_random_lejanos", help="Naive con listas random en rango 1-100000", action='store_true')
    parser.add_argument("--repes", help="Cantidad de repeticiones", default=repes, type=int)

    args = parser.parse_args()
    repes = args.repes

    if args.naive_random_cercanos:
        print("Inicia: exp_naive_random_cercanos")
        start_time = time.time()
        exp_naive_random(path_random_cercanos, 20)
        print("--- %s seconds ---" % (time.time() - start_time))

    if args.naive_random_lejanos:   
        print("Inicia: exp_naive_random_lejanos")
        start_time = time.time()
        exp_naive_random(path_random_lejanos, 200000)
        print("--- %s seconds ---" % (time.time() - start_time))



    # print(args)
