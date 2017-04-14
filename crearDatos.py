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
path_topdown = "datos/topdown/"
path_bottomup = "datos/bottomup/"

path_random = "random.csv"
path_creciente = "creciente.csv"
path_decreciente = "decreciente.csv"

tipo_naive = "naive"
tipo_poda = "poda"
tipo_topdown = "topdown"
tipo_bottomup = "bottomup"

repes = 20
cota_valor_maximo = 1000000
n_maximo_naive = 16
n_maximo_poda = 42 # Con 38 tarda 22 segundos
n_maximo_topdown = 95 # Con 100 tarda 1 minuto
n_maximo_bottomup = 145 # 145 en 154 segundos

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


def args_lista_creciente(tipo, n):
    return [ejecutable, tipo, str(n)] + [i for i in range(n)]


def exp_creciente(tipo, archivo, tamMaximo):
    with open(archivo, 'w') as f:
        for tam in range(1, tamMaximo+1):   # Instancias de tamaño n
            print("Crecientes " + str(tipo) + " de tamaño: " + str(tam))
            print("\nn:" + str(tam), file=f)
            for r in range(repes):   
                # Repito repes veces las pruebas con cada tamaño 
                # (instancias aleatorias cada vez) para ver mejor el caso promedio
                output = subprocess.check_output(args_lista_creciente(tipo, tam))
                print(str(output.decode()), file=f, end=""),


def args_lista_decreciente(tipo, n):
    return [ejecutable, tipo, str(n)] + [n-i for i in range(n)]


def exp_decreciente(tipo, archivo, tamMaximo):
    with open(archivo, 'w') as f:
        for tam in range(1, tamMaximo+1):   # Instancias de tamaño n
            print("Decrecientes " + str(tipo) + " de tamaño: " + str(tam))
            print("\nn:" + str(tam), file=f)
            for r in range(repes):   
                # Repito repes veces las pruebas con cada tamaño 
                # (instancias aleatorias cada vez) para ver mejor el caso promedio
                output = subprocess.check_output(args_lista_decreciente(tipo, tam))
                print(str(output.decode()), file=f, end=""),


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    
    parser.add_argument("-naive_todos", help="Todos los experimentos de naive", action='store_true')
    
    parser.add_argument("-naive_random", help="Naive con listas random."
                + " Tamaño maximo: " + str(n_maximo_naive), action='store_true')

    parser.add_argument("-poda_random", help="Poda con listas random."
                + " Tamaño maximo: " + str(n_maximo_poda), action='store_true')

    parser.add_argument("-topdown_random", help="Topdown con listas random."
             + " Tamaño maximo: " + str(n_maximo_topdown), action='store_true')

    parser.add_argument("-bottomup_random", help="Bottomup con listas random."
             + " Tamaño maximo: " + str(n_maximo_bottomup), action='store_true')

    parser.add_argument("-random", help="Todos las tecnicas con inputs randon")

    parser.add_argument("-creciente", help="Todos las tecnicas con inputs crecientes")

    parser.add_argument("-decreciente", help="Todos las tecnicas con inputs decrecientes")
    
    parser.add_argument("-iguales", help="Todos las tecnicas con inputs iguales")

    parser.add_argument("--repes", help="Cantidad de repeticiones", default=repes, type=int)

    args = parser.parse_args()
    repes = args.repes


    if args.random:
        print ("Inicia RANDOM")
        start_time = time.time()
        exp_creciente(tipo_naive, path_naive + path_random, n_maximo_naive)
        exp_creciente(tipo_poda, path_poda + path_random, n_maximo_poda)
        exp_creciente(tipo_topdown, path_topdown + path_random, n_maximo_topdown)
        exp_creciente(tipo_bottomup, path_bottomup + path_random, n_maximo_bottomup)
        print("--- %s seconds ---" % (time.time() - start_time))

    if args.creciente:
        print ("Inicia CRECIENTES")
        start_time = time.time()
        exp_creciente(tipo_naive, path_naive +  path_creciente, n_maximo_naive)
        exp_creciente(tipo_poda, path_poda + path_creciente, n_maximo_poda)
        exp_creciente(tipo_topdown, path_topdown + path_creciente, n_maximo_topdown)
        exp_creciente(tipo_bottomup, path_bottomup + path_creciente, n_maximo_bottomup)
        print("--- %s seconds ---" % (time.time() - start_time))

    if args.decreciente:
        print ("Inicia DECRECIENTES")
        start_time = time.time()
        exp_decreciente(tipo_naive, path_naive + path_decreciente, n_maximo_naive)
        exp_decreciente(tipo_poda, path_poda + path_decreciente, n_maximo_poda)
        exp_decreciente(tipo_topdown, path_topdown + path_decreciente, n_maximo_topdown)
        exp_decreciente(tipo_bottomup, path_bottomup + path_decreciente, n_maximo_bottomup)
        print("--- %s seconds ---" % (time.time() - start_time))
        


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

    if args.topdown_random:
        print("Inicia: exp_topdown_random")
        start_time = time.time()
        exp_random(tipo_topdown, path_topdown + path_random, n_maximo_topdown)
        print("--- %s seconds ---" % (time.time() - start_time))

    if args.bottomup_random:
        print("Inicia: exp_bottomup_random")
        start_time = time.time()
        exp_random(tipo_bottomup, path_bottomup + path_random, n_maximo_bottomup)
        print("--- %s seconds ---" % (time.time() - start_time))
