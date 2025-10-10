for _ in range(int(input())) :
    amount = int(input())
    _, *coins = map(int, input().split())
    dp = [0] * (amount + 1)
    dp[0] = 1
    for coin in coins :
        for amt in range(coin, amount + 1) :
            dp[amt] += dp[amt - coin]
    print(dp[amount])

