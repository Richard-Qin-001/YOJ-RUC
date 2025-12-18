# ____qcodep____
def func(n, a):
    result = 0
    num = 0
    for i in range(n):
        num = num * 10 + a
        result += num
    return result

n,a = input().split()
n = int(n)
a = int(a)
num = func(n,a)
print(num)
