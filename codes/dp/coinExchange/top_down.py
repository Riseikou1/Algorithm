amount = [1, 5, 10, 21, 25]
def dfs(n) :
    dp = [[float('inf'), []] for _ in range(n + 1)]
    dp[0][0] = 0
    for i in range(n + 1) :
        for a in amount :
            if a > i : break
            if dp[i - a][0] + 1 < dp[i][0] :
                dp[i][0] = dp[i - a][0] + 1
                dp[i][1] = dp[i - a][1] + [a]

    return dp[n][0], dp[n][1]

def space_optimized(n) :
    dp = [float('inf')] * (n + 1)
    parent = [-1] * (n + 1)
    dp[0] = 0 

    for i in range(1, n + 1):
        for a in amount:
            if a > i:
                break
            if dp[i - a] + 1 < dp[i]:
                dp[i] = dp[i - a] + 1
                parent[i] = a

    path = []
    cur = n
    while cur > 0 and parent[cur] != -1:
        path.append(parent[cur])
        cur -= parent[cur]

    return dp[n], path


n = int(input("Enter the coin amount : "))
count, path = dfs(n)
print("minimum coins needed : ", count)
print("used coins : ", path)
