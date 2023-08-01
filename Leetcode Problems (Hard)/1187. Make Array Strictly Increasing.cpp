class Solution {
public:

    static const int N = 2005;
    int mem[N][N];

    int go(int i, int prev, vector<int> &arr1, vector<int> &arr2){
        if (i == (int)arr1.size())
            return 0;
        
        int &ret = mem[i][prev];
        if (~ret)
            return ret;
        ret = 1e9;

        int now = arr1[i];
        int before = prev > 0 ? arr2[prev] : arr1[i - 1];
        
        // Making no changes.
        if (now > before)
            ret = min(ret, go(i + 1, 0, arr1, arr2));
        
        // Changing the current number to be the upper bound of it the previous number.
        auto it = upper_bound(arr2.begin(), arr2.end(), before);
        if (it != arr2.end())
            ret = min(ret, 1 + go(i + 1, it - arr2.begin(), arr1, arr2));
        
        return ret;
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        memset(mem, -1, sizeof(mem));
        sort(arr2.begin(), arr2.end());
        
        // Making arrays 1-based.
        vector<int> newArr1(1, -1);
        for(int num : arr1) newArr1.push_back(num);
        vector<int> newArr2(1, -1);
        for(int num : arr2) newArr2.push_back(num);

        int ans = go(1, 0, newArr1, newArr2);
        return ans == 1e9 ? -1 : ans;
    }
};