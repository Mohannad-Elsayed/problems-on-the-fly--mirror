import math
pw = int(pow(2, 100))
def slvone():
    n = int(input())
    l, r = 1, pw
    ans = 0

    while l <= r:
        mid = l + (r - l) // 2
        plapla = int(math.sqrt(mid))
        
        if mid - plapla >= n:
            ans = mid
            r = mid - 1
        else:
            l = mid + 1

    print(ans)

for x in range(int(input())):
    slvone()