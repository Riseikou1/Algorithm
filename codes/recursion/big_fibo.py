MOD = 10 ** 9 + 7

def multiply(A, B) :
    C = [[0, 0], [0, 0]]
    for i in range(2) :
        for j in range(2) :
            for k in range(2) :
                C[i][j] += (A[i][k] * B[k][j]) % MOD
    return C

def matrix_pow(A, p) :
    result = [[1, 0], [0, 1]]
    while p > 0 :
        if p % 2 == 1 :
            result = multiply(result, A)
        A = multiply(A, A)
        p //= 2
    return result

def fib_matrix(n) :
    if n <= 1 : return n
    T = [[1, 1], [1, 0]]
    T = matrix_pow(T, n - 1)
    return T[0][0]

if __name__ == "__main__" :
    n = 100
    print(f"F({n}) modded by {MOD} = {fib_matrix(n)}")


    big_n = 10 ** 18
    print(f"F({big_n}) modded by {MOD} = {fib_matrix(big_n)}")
