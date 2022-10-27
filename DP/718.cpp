class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int ans = 0;
        vector<vector<int>> dp(m, vector<int>(n));
        
        for(int i=0;i<n;i++) {
            if(nums1[0] == nums2[i]) dp[0][i] = 1;
            ans = max(ans, dp[0][i]);
        }
        
        for(int i=0;i<m;i++) {
            if(nums2[0] == nums1[i]) dp[i][0] = 1;
            ans = max(ans, dp[i][0]);
        }
        
        
        for(int i=1;i<m;i++) {
            for(int j=1;j<n;j++) {
                if(nums1[i] == nums2[j]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        
        return ans;
    }
};                        
