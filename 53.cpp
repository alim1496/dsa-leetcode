class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int current_sum = 0;
        
        for(int n:nums) {
            current_sum = max(n, current_sum+n);
            max_sum = max(current_sum, max_sum);
        }
        
        return max_sum;
    }
};

