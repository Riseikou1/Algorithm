memo = {}
def helper(n, k) :
    if k > n : return 0
    if k == 0 or n == 0 or n == k :
        return 1
    
    if (n, k) in memo :
        return memo[(n, k)]
    
    memo[(n, k)] = helper(n  - 1, k) + helper(n - 1, k - 1)
    return memo[(n, k)]

for _ in range(int(input())) :
    input_str = input()
    a, b = int(input_str.split()[0]), int(input_str.split()[1])
    print(helper(a, b) % 10007)
