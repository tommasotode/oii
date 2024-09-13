#!/usr/bin/env python3

N = int(input().strip())
S = input().strip()

d = {
    "q": "w",
    "a": "s",
    "z": "x",
    "w": "e",
    "s": "d",
    "x": "c",
    "e": "r",
    "d": "f",
    "c": "v",
    "r": "t",
    "f": "g",
    "v": "b",
    "t": "y",
    "g": "h",
    "b": "n",
    "y": "u",
    "h": "j",
    "n": "m",
    "u": "i",
    "j": "k",
    "m": "",
    "i": "o",
    "o": "p",
    "p": "",
    "k": "l",
    "l": "",
}

sol = ""
for c in S:
    sol += d[c]

print(sol)
