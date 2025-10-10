for _ in range(int(input())) :
    arr = list(map(int, input().split()))
    arr = arr[1 :]
    res = [float('-inf'), None, None]
    cur_sum = float("-inf")
    cur_start = 0
    
    for i, num in enumerate(arr) :
        if cur_sum < 0 :
            if num == 0 :
                cur_sum, cur_start = float('-inf'), i + 1
            else :
                cur_sum, cur_start = num, i

        else : cur_sum += num
            
        if cur_sum == float("-inf") or arr[cur_start] == 0 : continue
    
        if cur_sum > res[0] : 
            res = [cur_sum, cur_start, i]
            
        elif cur_sum == res[0] and cur_start < res[1] :
            res[1], res[2] = cur_start, i

    if res[0] < 0 :
        print(0, -1,-1)
    else :
        print(res[0], res[1], res[2])
