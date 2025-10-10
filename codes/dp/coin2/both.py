coins = [1, 2, 3, 5]
res = []

def bottom_up(idx, total, path):
    if total == 0:
        res.append(path)
        return
    
    for i in range(idx, len(coins)):
        if coins[i] > total: break
        bottom_up(i, total - coins[i], path + [coins[i]])

def top_down(total):
    dp = [0] * (total + 1)
    dp[0] = 1

    for coin in coins :
        for amt in range(coin, total + 1) :
            dp[amt] += dp[amt -coin]

    return dp[total]

coin = int(input("Enter the coin amount: "))
bottom_up(0, coin, [])
print("All possible ways : ", len(res))
print("Coin combinations : ", res)
