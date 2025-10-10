def pisda(word1, word2) :
    memo = {}
    def dfs(i, j) :
        if i >= len(word1) or j >= len(word2) : return 0
    
        if (i, j) in memo :
            return memo[(i, j)]
            
        res = 0
        if word1[i] == word2[j] :
            res += dfs(i + 1, j + 1) + 1
            
        else :
            res += max(dfs(i + 1, j), dfs(i, j + 1))
        
        memo[(i, j)] = res
        return res
        
    return dfs(0, 0)
    
for _ in range(int(input())) :
    input_str = str(input())
    word1, word2 = input_str.split()
    print(pisda(word1, word2))
