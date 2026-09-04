class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long minOperations = 0;
        int sz = nums.size();
        for (int i = sz - 1; i > 0; i--) {
            if (nums[i] < nums[i - 1]) {
                minOperations += (nums[i - 1] - nums[i]);
                nums[i] = nums[i - 1];
            }
        }
        return minOperations;
    }
};