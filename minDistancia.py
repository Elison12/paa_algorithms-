import math
import sys


class Ponto:
    def __init__(self, x, y):
        self.x = x
        self.y = y


def calcDistancia(a, b):
    distancia = math.sqrt(math.pow(int(b.x) - int(a.x), 2) +
                          math.pow(int(b.y) - int(a.y), 2))
    return distancia


def minDistancia(arr, n):

    menor = sys.maxsize

    for i in range(n-1):
        for j in range(i+1, n):
            dis = calcDistancia(arr[i], arr[j])
            if dis < menor:
                menor = dis

    return menor


if __name__ == "__main__":

    n = int(input())
    lista = []

    for i in range(n):
        ix, iy = input().split(" ")
        lista.append(Ponto(ix, iy))

    menorDistancia = minDistancia(lista, n)
    print('{:.4f}'.format(menorDistancia))
