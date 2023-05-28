#!/usr/bin/env python3

import sys

# se preferisci leggere e scrivere da file
# ti basta decommentare le seguenti due righe:

# sys.stdin = open('input.txt')
# sys.stdout = open('output.txt', 'w')

# prima cosa da fare:
	# se sum() dei numeri di colori * ogni loro lunghezza è minore del muro, allora il numero è uguale al numero di colori
	# (con * NON è moltiplicazione, ma un ciclo di somme)


def substitute(arr, i, new_elem):
	arr[i] = new_elem
	

# DA FINIRE

# c incrementa ogni volta e rappresenta il colore, sono i numeri con cui andrò a fillare l'array prima di contare tutti 
# i numeri diversi fra di loro.
def solve_piece(arr, n, c):
	length = len(arr)
	if n >= length:
		for i in range(length):
			arr[i] = c

	else:
		j = int(len(arr) / 2)
		while j + n > length:
			j -= 1
		for i in range(length):
			pass

def conta_diversi(arr):
	return 42

def solve():
	input() # prima riga vuota

	N, Q = map(int, input().split())
	L = list(map(int, input().split()))


	# 0 = bianco

	muro = []
	for i in range(N):
		muro.append(0)
	
	for j in range(Q):
		solve_piece(muro, L[j], j)
	



	# aggiungi codice...
	risposta = 42

	print(f"Case #{t}: {risposta}")


T = int(input().strip())

for t in range(1, T + 1):
	solve()