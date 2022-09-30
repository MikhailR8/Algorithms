k = 100
for n in range(1, 100):
    p = (n ** 3 - 1) ** (1/3) - n
    if p > k:
        print(False, n)
    k = p
print(True)
