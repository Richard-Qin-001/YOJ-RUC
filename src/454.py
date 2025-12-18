# ____qcodep____

def compute_standard_deviation(*arg):
    data = sorted(list(arg))
    data = data[1:-1]
    n = len(data)
    if n == 0:
        return 0.0
    mean = sum(data) / n

    variance = sum((x - mean) ** 2 for x in data) / (n - 1)
    return variance ** 0.5

nums = list(map(float, input().split()))
if(len(nums) >= 4):
    print('%.2f' % compute_standard_deviation(*nums))