import decimal
decimal.getcontext().prec = 20
# print(decimal.getcontext())
# a = decimal.Decimal('10.5')
# b = decimal.Decimal('.5')
# print(b/a)
for _ in range(int(input())):
    a, b = input().split()
    a = decimal.Decimal(a)
    b = decimal.Decimal(b)
    # print(a, b)
    # print((a.log10()) * b)
    print(int((a.log10() * b)) + 1)