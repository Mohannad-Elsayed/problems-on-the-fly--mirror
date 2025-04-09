import decimal
decimal.getcontext().prec = 500
# print(decimal.getcontext())
# a = decimal.Decimal('10.5')
# b = decimal.Decimal('.5')
# print(b/a)
for _ in range(int(input())):
    a, b = input().split()
    a = decimal.Decimal(a)
    b = decimal.Decimal(b)
    # print(a, b)
    print(int((a.log10() * b).to_integral_value()) + 1)