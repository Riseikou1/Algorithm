"""
for _ in range(int(input())) :
    length = input().split()[0]
    lst = list(map(int, input().split()))
    lst = [0] + sorted(lst) + [int(length)]
    n = len(lst)
    dp = [[0] * n for _ in range(n)]

    for size in range(2, n) :
        for l in range(n - size) :
            r = l + size
            dp[l][r] = float('inf')
            for k in range(l + 1, r) :
                cost = lst[r] - lst[l] + dp[l][k] + dp[k][r]
                dp[l][r] = min(dp[l][r], cost)
                
    print(dp[0][n - 1])
"""

for _ in range(int(input())) :
    memo = {}
    length = input().split()[0]
    lst = list(map(int, input().split()))
    lst = [0] + sorted(lst) + [int(length)]
    
    def helper(l, r) :
        if r - l <= 1 : return 0
        if (l, r) in memo :
            return memo[(l, r)]
        
        res = float('inf')
        cur_len = lst[r] - lst[l]

        for i in range(l + 1, r) :
            tmp = helper(l, i) + helper(i, r) + cur_len
            res = min(res, tmp)
        
        memo[(l, r)] = res
        return res

    print(helper(0, len(lst) - 1))
