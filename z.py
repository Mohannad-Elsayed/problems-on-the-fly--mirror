import sys
from functools import lru_cache

MOD = int(1e9 + 7)

def sol(i, start, en, minus, n, v):
    if i == n or (start == 1 and en == 1):
        return 0 if minus else 1

    if dp[i][start][en][minus] != -1:
        return dp[i][start][en][minus]

    ret = 1
    if not start:
        ret = max(ret % MOD,
                  (abs(v[i]) % MOD * sol(i + 1, 1, en, minus ^ (v[i] < 0), n, v) % MOD),
                  sol(i + 1, 0, 0, 0, n, v))
    if start:
        ret = max(ret % MOD,
                  (abs(v[i]) % MOD * sol(i + 1, 1, en, minus ^ (v[i] < 0), n, v) % MOD) % MOD)
    if start and not en:
        ret = max(ret % MOD,
                  (abs(v[i]) % MOD * sol(i + 1, 1, 1, minus ^ (v[i] < 0), n, v) % MOD) % MOD)

    dp[i][start][en][minus] = ret
    return ret

def afroos():
    global dp
    n = int(input())
    v = list(map(int, input().split()))
    dp = [[[[-1 for _ in range(2)] for _ in range(2)] for _ in range(2)] for _ in range(n)]
    print(sol(0, 0, 0, 0, n, v))

if __name__ == "__main__":
    sys.setrecursionlimit(200000)
    T = 1
    # T = int(input())
    for _ in range(T):
        afroos()