# ____qcodep____

def lcm2(*args):
    def gcd(x, y):
        while y:
            x, y = y, x % y
        return x
    def _lcm(x, y):
        if x == 0 or y == 0: return 0
        return abs(x * y) // gcd(x, y)
    
    if not args:
        return 0
    
    res = args[0]
    for i in range(1, len(args)):
        res = _lcm(res, args[i])
    
    return res

numbers = map(int,input().split())
res = lcm2(*numbers)
print(res)