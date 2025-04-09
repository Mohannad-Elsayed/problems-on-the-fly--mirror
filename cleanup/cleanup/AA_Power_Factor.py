sum = 0
for i in range(2, 257, 2):
    cnt = 0
    ti = i
    while ti % 2 == 0:
        cnt += 1
        ti //= 2
    sum += cnt
    print(i, sum, ' ', 2**(i//2 -1))
    # print(cnt, end=" ")
    