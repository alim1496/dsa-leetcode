class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int dp[n+1][amount+1];
        
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=amount;j++) {
                dp[i][j] = i==0 ? INT_MAX - 1 : 0;
            }
        }
        
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=amount;j++) {
                if(j < coins[i-1]) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i-1]] + 1);
                }
            }
        }
        
        return dp[n][amount] == INT_MAX - 1 ? -1 : dp[n][amount];
    }
};
