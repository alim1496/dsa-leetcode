// memoised recursion
class Solution {
public:
    int dp[101];
    int helper(vector<int>& nums, int house) {
        if(house >= nums.size()) return 0;
        if(dp[house] != -1) return dp[house];
        
        int current = house;
        int sum = 0;
        sum += nums[current];
        current += 2;
        
        return dp[house] = max(sum + helper(nums, current), helper(nums, house + 1));
    }
    
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        return helper(nums, 0);
    }
};

// tabular
class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[nums.size()+1];
        dp[nums.size()] = 0;
        for(int i=nums.size()-1;i>=0;i--) {
            int current = i;
            int sum = 0;
            sum += nums[current];
            current += 2;
            if(current < nums.size()) sum += dp[current];
            dp[i] = max(sum, dp[i + 1]);
        }
        return dp[0];
    }
};
