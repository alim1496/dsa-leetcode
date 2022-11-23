class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size()-1, k = 0;
        while(k <= right) {
            if(nums[k] == 0) {
                swap(nums[k++], nums[left++]);
            } else if(nums[k] == 1) {
                k++;
            } else {
                swap(nums[k], nums[right--]);
            }
        }
    }
};
