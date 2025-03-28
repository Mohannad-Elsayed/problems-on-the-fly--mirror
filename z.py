import sys
sys.stdout = open("h1", 'wt')

t = 1000
print(t)
n = int(1e4)
for _ in range(t):
    print(n)