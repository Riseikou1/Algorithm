memo = {}
def helper(lst, target) :
    if target == 0 :
        return 0
    if target in memo :
        return memo[target]
    
    res = float('inf')
    for num in lst :
        if target - num < 0 :
            break
        res = min(res, helper(lst, target - num) + 1)
    
    memo[target] = res
    return memo[target]

for _ in range(int(input())) :
    memo = {}
    target = int(input())
    lst = list(map(int, input().split()))[1:]

    print(helper(sorted(lst), target))
