it_count = int(input())
for _ in range(it_count) :
    array_len = int(input())
    min_num, max_num = float('inf'), float('-inf')
    inputt = str(input())
    nums = inputt.split()
    for i in range(array_len) :
        num = int(nums[i])
        min_num = min(min_num, num)
        max_num = max(max_num, num)

    print(max_num, min_num)

