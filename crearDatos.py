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
path_iguales = "iguales.csv"

tipo_naive = "naive"
tipo_poda = "poda"
tipo_topdown = "topdown"
tipo_bottomup = "bottomup"

repes = 20
cota_valor_maximo = 1000000
n_maximo_naive = 16 #16
n_maximo_poda = 40 # Con 38 tarda 22 segundos
n_maximo_topdown = 130 # Con 100 tarda 1 minuto
n_maximo_bottomup = 150 # 145 en 154 segundos

def args_lista_random(tipo, n):
    return [ejecutable, tipo, str(n)] + [str(random.randrange(1, cota_valor_maximo+1)) for _ in range(n)]

def exp_random(tipo, archivo, tamMaximo):
    with open(archivo, 'w') as f:
        # header
        for header in range(repes):   
            # Repito repes veces las pruebas con cada tamaño 
            # (instancias aleatorias cada vez) para ver mejor el caso promedio
            # output = subprocess.check_output(args_lista_random(tipo, tam))
            print("R" + str(header) + "," , file=f, end=""),
        print("", file=f)

        for tam in range(1, tamMaximo+1):   # Instancias de tamaño n
            print("Random " + str(tipo) + " de tamaño: " + str(tam))
            # print("\nn:" + str(tam), file=f)
            for r in range(repes):   
                # Repito repes veces las pruebas con cada tamaño 
                # (instancias aleatorias cada vez) para ver mejor el caso promedio
                output = subprocess.check_output(args_lista_random(tipo, tam))
                print(str(output.decode()), file=f, end=""),
            print("", file=f)

def args_lista_creciente(tipo, n):
    return [ejecutable, tipo, str(n)] + [str(i) for i in range(n)]


def exp_creciente(tipo, archivo, tamMaximo):
    with open(archivo, 'w') as f:
        # header
        for header in range(repes):   
            # Repito repes veces las pruebas con cada tamaño 
            # (instancias aleatorias cada vez) para ver mejor el caso promedio
            # output = subprocess.check_output(args_lista_random(tipo, tam))
            print("R" + str(header) + "," , file=f, end=""),
        print("", file=f)

        for tam in range(1, tamMaximo+1):   # Instancias de tamaño n
            print("Crecientes " + str(tipo) + " de tamaño: " + str(tam))
            # print("\nn:" + str(tam), file=f)
            for r in range(repes):   
                # Repito repes veces las pruebas con cada tamaño 
                # (instancias aleatorias cada vez) para ver mejor el caso promedio
                output = subprocess.check_output(args_lista_creciente(tipo, tam))
                print(str(output.decode()), file=f, end=""),
            print("", file=f)


def args_lista_decreciente(tipo, n):
    return [ejecutable, tipo, str(n)] + [str(n-i) for i in range(n)]


def exp_decreciente(tipo, archivo, tamMaximo):
    with open(archivo, 'w') as f:
        # header
        for header in range(repes):   
            # Repito repes veces las pruebas con cada tamaño 
            # (instancias aleatorias cada vez) para ver mejor el caso promedio
            # output = subprocess.check_output(args_lista_random(tipo, tam))
            print("R" + str(header) + "," , file=f, end=""),
        print("", file=f)

        for tam in range(1, tamMaximo+1):   # Instancias de tamaño n
            print("Decrecientes " + str(tipo) + " de tamaño: " + str(tam))
            # print("\nn:" + str(tam), file=f)
            for r in range(repes):   
                # Repito repes veces las pruebas con cada tamaño 
                # (instancias aleatorias cada vez) para ver mejor el caso promedio
                output = subprocess.check_output(args_lista_decreciente(tipo, tam))
                print(str(output.decode()), file=f, end=""),

            print("", file=f)


def args_lista_iguales(tipo, n):
    return [ejecutable, tipo, str(n)] + ["1" for i in range(n)]


def exp_iguales(tipo, archivo, tamMaximo):
    with open(archivo, 'w') as f:
        # header
        for header in range(repes):   
            # Repito repes veces las pruebas con cada tamaño 
            # (instancias aleatorias cada vez) para ver mejor el caso promedio
            # output = subprocess.check_output(args_lista_random(tipo, tam))
            print("R" + str(header) + "," , file=f, end=""),
        print("", file=f)

        for tam in range(1, tamMaximo+1):   # Instancias de tamaño n
            print("Iguales " + str(tipo) + " de tamaño: " + str(tam))
            # print("\nn:" + str(tam), file=f)  
            for r in range(repes):   
                # Repito repes veces las pruebas con cada tamaño 
                # (instancias aleatorias cada vez) para ver mejor el caso promedio
                output = subprocess.check_output(args_lista_iguales(tipo, tam))
                print(str(output.decode()), file=f, end=""),
            print("", file=f)

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    
    parser.add_argument("-naive_todos", help="Todos los experimentos de naive", action='store_true')
    
    parser.add_argument("-naive_random", help="Naive con listas random."
                + " Tamaño maximo: " + str(n_maximo_naive), action='store_true')

    parser.add_argument("-poda_random", help="Poda con listas random."
                + " Tamaño maximo: " + str(n_maximo_poda), action='store_true')

    parser.add_argument("-poda_iguales", help="Poda con listas iguales.", action='store_true')

    parser.add_argument("-poda_creciente", help="Poda con listas crecientes.", action='store_true')

    # parser.add_argument("-topdown_random", help="Topdown con listas random."
    #          + " Tamaño maximo: " + str(n_maximo_topdown), action='store_true')

    parser.add_argument("-bottomup_random", help="Bottomup con listas random."
             + " Tamaño maximo: " + str(n_maximo_bottomup), action='store_true')

    parser.add_argument("-random", help="Todos las tecnicas con inputs randon", action='store_true')

    parser.add_argument("-creciente", help="Todos las tecnicas con inputs crecientes", action='store_true')

    parser.add_argument("-decreciente", help="Todos las tecnicas con inputs decrecientes", action='store_true')
    
    parser.add_argument("-iguales", help="Todos las tecnicas con inputs iguales", action='store_true')
    
    parser.add_argument("-topdown_random", help="Todos las tecnicas con inputs randon", action='store_true')

    parser.add_argument("-topdown_creciente", help="Todos las tecnicas con inputs crecientes", action='store_true')

    parser.add_argument("-topdown_decreciente", help="Todos las tecnicas con inputs decrecientes", action='store_true')
    
    parser.add_argument("-topdown_iguales", help="Todos las tecnicas con inputs iguales", action='store_true')

    parser.add_argument("--repes", help="Cantidad de repeticiones", default=repes, type=int)

    args = parser.parse_args()
    repes = args.repes


    if args.random:
        print ("Inicia RANDOM")
        start_time = time.time()
        exp_random(tipo_naive, path_naive + path_random, n_maximo_naive)
        exp_random(tipo_poda, path_poda + path_random, n_maximo_poda)
        exp_random(tipo_topdown, path_topdown + path_random, n_maximo_topdown)
        exp_random(tipo_bottomup, path_bottomup + path_random, n_maximo_bottomup)
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

    if args.iguales:
        print ("Inicia IGUALES")
        start_time = time.time()
        exp_iguales(tipo_naive, path_naive + path_iguales, n_maximo_naive)
        exp_iguales(tipo_poda, path_poda + path_iguales, n_maximo_poda)
        exp_iguales(tipo_topdown, path_topdown + path_iguales, n_maximo_topdown)
        exp_iguales(tipo_bottomup, path_bottomup + path_iguales, n_maximo_bottomup)
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

    if args.poda_iguales:
        print("Inicia: exp_poda_iguales")
        start_time = time.time()
        exp_iguales(tipo_poda, path_poda + path_iguales, 190)
        print("--- %s seconds ---" % (time.time() - start_time))

    if args.poda_creciente:
        print("Inicia: exp_poda_creciente")
        start_time = time.time()
        exp_creciente(tipo_poda, path_poda + path_creciente, 190)
        print("--- %s seconds ---" % (time.time() - start_time))

    if args.topdown_random:
        print("Inicia: exp_topdown_random")
        start_time = time.time()
        exp_random(tipo_topdown, path_topdown + path_random, n_maximo_topdown)
        print("--- %s seconds ---" % (time.time() - start_time))

    if args.topdown_creciente:
        print("Inicia: exp_topdown_creciente")
        start_time = time.time()
        exp_creciente(tipo_topdown, path_topdown + path_creciente, n_maximo_topdown)
        print("--- %s seconds ---" % (time.time() - start_time))
    
    if args.topdown_iguales:
        print("Inicia: exp_topdown_creciente")
        start_time = time.time()
        exp_iguales(tipo_topdown, path_topdown + path_iguales, n_maximo_topdown)
        print("--- %s seconds ---" % (time.time() - start_time))

    if args.bottomup_random:
        print("Inicia: exp_bottomup_random")
        start_time = time.time()
        exp_random(tipo_bottomup, path_bottomup + path_random, n_maximo_bottomup)
        print("--- %s seconds ---" % (time.time() - start_time))
