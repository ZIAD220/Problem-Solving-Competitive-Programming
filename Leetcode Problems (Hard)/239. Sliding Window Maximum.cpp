class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> ms;
        for(int i = 0; i < k; i++)
            ms.insert(nums[i]);
        
        vector<int> ans = {*ms.rbegin()};
        
        for(int i = k; i < (int)nums.size(); i++){
            ms.erase(ms.find(nums[i - k]));
            ms.insert(nums[i]);
            ans.push_back(*ms.rbegin());
        }

        return ans;
    }
};