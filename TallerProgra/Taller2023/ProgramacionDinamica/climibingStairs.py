class Solution:
    #cantidad de caminos desde el escalon i
    dp = [0]*46
    visited = [False]*46
    def caminosDesde(self, i, n):
        if i == n-1:
            return 1
        elif i == n-2:
            return 2
        else:
            if not self.visited[i]:
                self.visited[i] = True
                self.dp[i] = self.caminosDesde(i+1, n) + self.caminosDesde(i+2, n)
            return self.dp[i]

    #podemos verlo como que hay n+1 escalones, del 0 al n
    # y quiero saber los caminos desde el escalon 0 hasta el n
    def climbStairs(self, n: int) -> int:
        return self.caminosDesde(0, n)    


s = Solution()
print(s.climbStairs(4))