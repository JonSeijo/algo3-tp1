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

path_random = "random.csv"

tipo_naive = "naive"
tipo_poda = "poda"
tipo_topdown = "topdown"
tipo_bottomup = "bottomup"

repes = 25
cota_valor_maximo = 200000
n_maximo_naive = 15
n_maximo_poda = 32

def args_lista_random(tipo, n):
    return [ejecutable, tipo, str(n)] + [str(random.randrange(1, cota_valor_maximo+1)) for _ in range(n)]

def exp_random(tipo, archivo, tamMaximo):
    with open(archivo, 'w') as f:
        for tam in range(1, tamMaximo+1):   # Instancias de tamaño n
            print("Instancias random de tamaño: " + str(tam))
            print("\nn:" + str(tam), file=f)
            for r in range(repes):   
                # Repito repes veces las pruebas con cada tamaño 
                # (instancias aleatorias cada vez) para ver mejor el caso promedio
                output = subprocess.check_output(args_lista_random(tipo, tam))
                print(str(output.decode()), file=f, end=""),

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument("-naive_todos", help="Todos los experimentos de naive", action='store_true')
    parser.add_argument("-naive_random", help="Naive con listas random. Elementos con cota " + str(cota_valor_maximo), action='store_true')
    parser.add_argument("-poda_random", help="Poda con listas random. Elementos con cota " + str(cota_valor_maximo), action='store_true')
    parser.add_argument("--repes", help="Cantidad de repeticiones", default=repes, type=int)

    args = parser.parse_args()
    repes = args.repes

    if args.naive_random:
        print("Inicia: exp_naive_random")
        start_time = time.time()
        exp_random(tipo_naive, path_naive +  path_random, n_maximo_naive)
        print("--- %s seconds ---" % (time.time() - start_time))

    if args.poda_random:
        print("Inicia: exp_poda_random")
        start_time = time.time()
        exp_random(tipo_poda, path_poda + path_random, n_maximo_poda)
        print("--- %s seconds ---" % (time.time() - start_time))
