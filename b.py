def sm(n):
    s = 0
    for i in range(n+1):
        s += i*i
    return s
def smm(n):
    return n*n
# for i in range(11):
#     print(i, ":", smm(i)%10)
s = 0
# for i in range(101, 201):
#     s += smm(i)%10
#     s %= 10
#     # print(i, ":", s)
#     print(s)
print(sm(int(input()))%10)