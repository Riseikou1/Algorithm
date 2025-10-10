def lcs(word1, word2):
    n, m = len(word1), len(word2)
    dp = [[0] * (m + 1) for _ in range(n + 1)]

    # Fill dp table
    for i in range(n - 1, -1, -1):
        for j in range(m - 1, -1, -1):
            if word1[i] == word2[j]:
                dp[i][j] = 1 + dp[i + 1][j + 1]
            else:
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1])

    # Reconstruct actual subsequence
    i, j = 0, 0
    ans = []
    while i < n and j < m:
        if word1[i] == word2[j]:
            ans.append(word1[i])
            i += 1
            j += 1
        elif dp[i + 1][j] >= dp[i][j + 1]:
            i += 1
        else:
            j += 1

    return dp[0][0], "".join(ans)


for _ in range(int(input())):
    w1, w2 = input().split()
    length, subseq = lcs(w1, w2)
    print(length, subseq)
