fibo_lengths = [1, 1]
for i in range(2, 50) :
    fibo_lengths.append(fibo_lengths[-1] + fibo_lengths[-2])

def solve(n, k) :
    if n == 0 : return 'b'
    if n == 1 : return 'a'
    prev_len = fibo_lengths[n - 1]
    if k < prev_len :
        return solve(n - 1, k)
    else :
        return solve(n - 2, k - prev_len)

for _ in range(int(input())) :
    input_str = str(input())
    n, k = input_str.split()
    res = solve(int(n), int(k))
    print(res)
