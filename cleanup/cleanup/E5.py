import sys
import random
# sys.stdout = open("E5", "wt")
random.seed(283746827364328749)
T = 1
N = 200000
K = 1
lstt = [x for x in range(N)]
random.shuffle(lstt)
print(T)
for _ in range(T):
    print(N, K)
    for i in range(len(lstt)):
        print(lstt[i], end='')
        if i+1 == len(lstt): print('\n', end='')
        else: print(' ', end='')