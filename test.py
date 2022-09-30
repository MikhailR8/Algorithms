N = int(input())
arr1 = []
arr2 = []
arr3 = []
for i in range(N):
    arr1.append(int(input()))
    if arr1[i] >= 0:
        arr2.append(arr1[i])
    else:
        arr3.append(arr1[i])
#print(arr1, arr2, arr3)
mn2 = arr2[0]
mn3 = abs(arr3[0])
length2 = len(arr2)
length3 = len(arr3)
for k in range(length2):  #было for k in range(N - length2 + 1):
    for i in range(len(arr2)):
        mn2 = min(mn2, arr2[i])
    arr1[k] = mn2
    arr2.remove(mn2)
    mn2 = 10 ** 8
#print(arr1, arr2, arr3)
for i in range(length3): #было for i in range(N - length2 + 1, N):
    for j in range(len(arr3)):
        mn3 = min(mn3, abs(arr3[j]))
    arr1[length2 + i] = -mn3 #arr1[i] = -mn3
    arr3.remove(-mn3)
    mn3 = 10 ** 8
s = ''
for i in range(N):
    s += str(arr1[i]) + ' '
print(s)