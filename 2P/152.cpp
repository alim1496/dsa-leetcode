class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int left = 1, right = 1, result = nums[0];
        for(int i=0;i<nums.size();i++) {
            left *= nums[i];
            right *= nums[nums.size()-1-i];
            result = max(result, max(left, right));
            if(left == 0) left = 1;
            if(right == 0) right = 1;
        }
        return result;
    }
};