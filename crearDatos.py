#encoding: utf-8

import argparse
import random
import subprocess
from sys import argv
from subprocess import call

ejecutable = "./tiempos"

path_naive = "datos/naive/"
path_poda = "datos/poda/"

path_random_cercanos = "random_cercanos.csv"
path_random_lejanos = "random_lejanos.csv"

repes = 10

def args_naive_lista_random(ejec, tam, tope):
    return [ejec, "naive", str(tam)] + [str(random.randrange(1, tope+1)) for _ in range(tam)]

def exp_naive_random_cercanos():
    tope = 20
    with open(path_naive + path_random_cercanos, 'w') as f:
        for tam in range(1, 10):
            print("\nn:" + str(tam), file=f)
            for r in range(repes):
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
        exp_naive_random_cercanos()

    if args.naive_random_lejanos:
        exp_naive_random_lejanos()



    # print(args)
