def sumR(mas):
    if not mas:
        return 0
    return mas[0] + sumR(mas[1:])

def countR(mas):
    if len(mas) == 0:
        return 0
    return 1 + countR(mas[1:])

def maxR(mas, m):
    if len(mas) == 0:
        return m
    if mas[0] > m:
        return maxR(mas[1:], mas[0])
    else:
        return maxR(mas[1:], m)

def maxR2(list):
    if len(list) == 2:
        return list[0] if list[0] > list[1] else list[1]
    sub_max = max(list[1:])
    return list[0] if list[0] > sub_max else sub_max

def binP(slist, num, l, h):
    if len(slist) == 1 and slist[0] == num:
        return l
    elif len(slist) == 1 and slist[0] != num:
        return False
    m = len(slist) // 2
    if num < slist[m]:
        return binP(slist[:m], num, l, m-1)
    if num > slist[m]:
        return binP(slist[m:], num, m, h)
    if num == slist[m]:
        return l + m


print(binP([10, 20, 30, 40, 50, 60], 12, 0, 6))
