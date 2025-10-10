memo = {0 : [0, []]}
amount = [1, 5, 10, 21, 25]
def dfs(total) :
    if total in memo : 
        return memo[total]
    best = float('inf')
    best_path = []
        
    for coin in amount :
        if coin <= total :
            sub_total, sub_path = dfs(total - coin)
            if sub_total + 1 < best :
                best = sub_total + 1
                best_path = sub_path + [coin]

    memo[total] = [best, best_path]
    return memo[total] 

def main():
    bill = int(input("Enter the bill amount : "))
    count, bills = dfs(bill)
    print("Minimum coins will be used : ",count)
    print("Coins used : ",bills)

if __name__ == "__main__" :
    main()
