#!/usr/bin/env python3

R, C = map(int, input().strip().split())
M = [None] * R
for i in range(R):
	M[i] = list(map(int, input().strip().split()))


# insert your code here
# se trovo un uno senza nessun altro uno in basso o a destra, aggiungo 1
n = 0
for i in range(C-1):
	for j in range(R-1):
		
		if M[i][j]:
			if M[i][j+1] == 0 and M[i+1][j] == 0:
				n += 1


print(n)
