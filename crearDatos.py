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
