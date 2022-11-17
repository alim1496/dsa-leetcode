// recursive memoization
class Solution {
public:
    int dp[101][101];
    int findUniquePaths(int m, int n) {
        if(m < 0 || n < 0) return 0;
        if(m == 1 && n == 1) return 1;
        if(dp[m][n] != -1) return dp[m][n];
        return dp[m][n] = findUniquePaths(m-1, n) + findUniquePaths(m, n-1);
    }
    
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return findUniquePaths(m, n);
    }
};

// tabular dp
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[101][101];
        for(int i=0;i<m;i++) {
            dp[i][0] = 1;
        }
        for(int i=0;i<n;i++) {
            dp[0][i] = 1;
        }
        for(int i=1;i<m;i++) {
            for(int j=1;j<n;j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
