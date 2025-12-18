# ____qcodep____ 

def lcm(a, b):
    c = 1
    d = a * b
    while(c != 0):
        c= a % b
        a = b
        b = c
    return int(d / a)

a, b = map(int,input().split())
print(lcm(a, b))