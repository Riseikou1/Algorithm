def print_parenthesis(split, i, j):
    if i == j:
        print(f"M{i+1}", end="")
        return
    print("(", end="")
    print_parenthesis(split, i, split[i][j])
    print_parenthesis(split, split[i][j] + 1, j)
    print(")", end="")


for _ in range(int(input())):
    n = int(input())
    dims = list(map(int, input().split()))  # n+1 integers

    # DP tables
    cost = [[0] * n for _ in range(n)]
    split = [[0] * n for _ in range(n)]

    # len_chain: chain length from 2 to n
    for length in range(2, n + 1):
        for i in range(n - length + 1):
            j = i + length - 1
            cost[i][j] = float('inf')

            for k in range(i, j):
                q = cost[i][k] + cost[k + 1][j] + dims[i] * dims[k + 1] * dims[j + 1]
                if q < cost[i][j]:
                    cost[i][j] = q
                    split[i][j] = k

    print_parenthesis(split, 0, n - 1)
    print()
    print(cost[0][n - 1])
