import sys

lst = []
# while len(lst) < int(2e5):
# _ = 0
# while True:
#     if _ * 20753 > int(1e9) or len(lst) >= int(2e5):
#         break
#     lst.append(_ * 20753)
#     _+=1

_ = 1
while True:
    if _ * 541 > int(2e5):
        _ = 1
    if _ * 541 > int(2e5) or len(lst) >= int(2e5):
        break
    lst.append(_ * 541)
    _+=1

# _ = 0
# while True:
#     if _ * 85229 > int(1e9) or len(lst) >= int(2e4):
#         break
#     lst.append(_ * 85229)
#     _+=1

while len(lst) < int(2e5):
    lst.append(541)

# print(lst)
# print(len(lst))

# sys.stdout = open("E4", "wt")
# T = 1
# N = len(lst)
# K = 2

# print(T)
# for _ in range(T):
#     print(N, K)
#     for i in range(len(lst)):
#         print(lst[i], end='')
#         if i+1 == len(lst): print('\n', end='')
#         else: print(' ', end='')

from random import shuffle
sys.stdout = open("E5", "wt")
T = 1
N = 200000
K = 1
lstt = [x for x in range(N)]
shuffle(lstt)
print(T)
for _ in range(T):
    print(N, K)
    for i in range(len(lst)):
        print(lstt[i], end='')
        if i+1 == len(lst): print('\n', end='')
        else: print(' ', end='')




