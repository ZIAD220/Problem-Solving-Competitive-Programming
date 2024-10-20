class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int l = 0, r = *max_element(nums.begin(), nums.end());
        int ans = 0;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if (countSmallerPairs(mid, nums) >= k) {
                r = mid - 1;
                ans = mid;
            }
            else {
                l = mid + 1;
            }
        }

        return ans;
    }

private:
    int countSmallerPairs(int mid, vector<int> &nums) {
        int l = 0, r = 1;
        int pairs = 0;
        while(l < nums.size()) {
            // Comparing how far we can go.
            while(r < nums.size() && nums[r] - nums[l] <= mid)
                r++;
            
            l++;
            pairs += r - l;
        }
        return pairs;
    }
};

/*

- Sort the distances.
- Binary search on the answer.
    - mid
    - if (countSmallerPairs(mid) == k)
        return mid;
    - if (countSmallerPairs(mid) > k)
        return r = mid - 1;
    - if (countSmallerPairs(mid) < k)
        return l = mid + 1;

    - CountSmallerPairs:
        - 1 1 3 4 7 9     mid = 5


1 1 6


*/