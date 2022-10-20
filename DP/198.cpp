// memoised recursion
class Solution {
public:
    int helper(vector<int>& nums, vector<int>& dp, int house) {
        if(house >= nums.size()) return 0;
        if(dp[house] != -1) return dp[house];
        
        return dp[house] = max(nums[house] + helper(nums, dp, house+2), helper(nums, dp, house + 1));
    }
    
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return helper(nums, dp, 0);
    }
};

// tabular
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp[n+1];
        dp[n] = 0;
        for(int i=nums.size()-1;i>=0;i--) {
            int current = i;
            int sum = nums[i];
            if(i+2 < n) sum += dp[i+2];
            dp[i] = max(sum, dp[i + 1]);
        }
        return dp[0];
    }
};
