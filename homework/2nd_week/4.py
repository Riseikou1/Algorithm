for _ in range(int(input())) :
    input_str = str(input())
    nums= input_str.split()
    ans = 1
    for char in nums[1:] :
        ans *= int(char) % 10
        ans %= 10

    print(ans)

