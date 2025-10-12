for _ in range(int(input())) :
    num = int(input())
    dp = [0] * (num + 1)

    for i in range(1, num + 1) :
        dp[i] = dp[i >> 1] + (i & 1)

    print(sum(dp))
