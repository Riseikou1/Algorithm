memo = {}

def helper(n, k) :
    if k > n : return 0  # Invalid case.
    if n == 0 or k == 0 : return 1
    if (n, k) in memo : 
        return memo[(n, k)]
    
    memo[(n, k)] = helper(n - 1, k) + helper(n - 1, k - 1)
    return memo[(n, k)]

def main():
    n = int(input("Enter n : "))
    k = int(input("Enter k : "))
    print(helper(n, k))
    
if __name__ == "__main__" :
    main()
