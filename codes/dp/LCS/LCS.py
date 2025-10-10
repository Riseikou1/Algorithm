def LCS(text1, text2):
    n, m = len(text1), len(text2)
    dp = [[""] * (m + 1) for _ in range(n + 1)]

    for i in range(n - 1, -1, -1):
        for j in range(m - 1, -1, -1):
            if text1[i] == text2[j]:
                dp[i][j] = text1[i] + dp[i + 1][j + 1]
            else:
                # pick the longer subsequence
                if len(dp[i + 1][j]) > len(dp[i][j + 1]):
                    dp[i][j] = dp[i + 1][j]
                else:
                    dp[i][j] = dp[i][j + 1]

    return dp[0][0]

def main():
    txt1 = input("Enter text1 : ")
    txt2 = input("Enter text2 : ")
    print("Longest common subsequence is:", LCS(txt1, txt2))

if __name__ == "__main__":
    main()
