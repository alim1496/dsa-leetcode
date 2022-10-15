class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int len = INT_MAX;
        
        int left = 0, right = 0;
        
        while(right < nums.size()) {
            sum += nums[right];
            if(sum >= target) {
                while(sum >= target) {
                    sum -= nums[left++];
                    if(sum < target) {
                        len = min(len, right-left+2);
                    }
                }
            }
            right++;
        }
        
        return len == INT_MAX ? 0 : len;
    }
};
