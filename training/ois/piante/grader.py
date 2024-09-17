from typing import List

def pollice_verde(N: int, H: List[int]) -> int:
    sol = 1

    state = ""
    if H[0] > H[1]:
        state = "desc"
    elif H[0] < H[1]:
        state = "asc"
    elif H[0] == H[1]:
        state = "stall"

    for i in range(N - 1):

        if H[i] < H[i + 1]:
            if state == "desc":
                sol += 1
            state = "asc"

        elif H[i] > H[i+1]:            
            state = "desc"

        elif H[i] == H[i+1]:            
            sol += 1
            state = "stall"

    return sol


if __name__ == "__main__":
    N = int(input())
    H = list(map(int, input().split()))

    print(pollice_verde(N, H))
