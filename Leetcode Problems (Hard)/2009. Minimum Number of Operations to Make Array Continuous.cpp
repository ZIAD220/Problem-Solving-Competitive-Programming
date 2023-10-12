class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int length = nums.size();
        vector<int> pre = {0, 0};
        for(int i = 1; i < length; i++)
            pre.push_back(pre.back() + (nums[i] == nums[i - 1]));

        int ans = length - 1;
        for(int i = 0; i < length; i++){
            int rightMax = nums[i] + length - 1;
            auto rightEnd = upper_bound(nums.begin() + i, nums.end(), rightMax);
            rightEnd--;
            
            int rightIndex = rightEnd - nums.begin();
            int curAns = i + (length - rightIndex - 1) + (pre[rightIndex + 1] - pre[i]);

            ans = min(ans, curAns);
        }

        return ans;
    }
};