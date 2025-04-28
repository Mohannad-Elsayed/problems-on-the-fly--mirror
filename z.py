n = int(input())
MOD = 10**9+7
minus1 = -1
if ((n+1)%2==0):
    minus1 = 1
ans = (((pow(3, n+1, MOD)+MOD%MOD) + 2)%MOD - 3 * minus1)//8 - 1
print(ans)