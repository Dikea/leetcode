class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        dp = list(range(amount + 1))
        size = len(coins)
   
        dp[0] = 0
        for i in range(1, amount + 1) :
            dp[i] = 10 ** 9
            for coin in coins : 
                if i >= coin : dp[i] = min(dp[i], dp[i - coin] + 1)
                
        return dp[amount] if dp[amount] != 10 ** 9 else -1
        
