# import sys
# import os
# import random
# random.seed(832746238746345)
# # os.makedirs("cleanup/hacks/", exist_ok = True)
# # sys.stdout = open("cleanup/hacks/E1", "w")
# powers = [2**x-1 for x in range(29,31)]
# for i in range(10):
#     powers.append(random.randint(2**29, 2**30-1))
# T = 1
# print(T)
# N = int(2e5//T)
# for __ in range(T):
#     print(N)
#     for _ in range(N): 
#         if _ == N-1:
#             print(0, end='\n')
#         else: print(0, end=' ')


print(1)
print(800)
for i in range(800):
    row = [i + j + 2 for j in range(800)]
    print(' '.join(map(str, row)))