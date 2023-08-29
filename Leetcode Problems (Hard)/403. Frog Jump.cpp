class Solution {
public:

    int n;
    vector<vector<int>> dp;
    map<int, int> pos;

    int go(int i, int k, vector<int>& stones){
        if (i == n - 1)
            return true;
        
        int &ret = dp[i][k];
        if (~ret)
            return ret;
        ret = 0;

        // Moving k - 1 units.
        if (k - 1 > 0 && pos.find(stones[i] + k - 1) != pos.end())
            ret = max(ret, go(pos[stones[i] + k - 1], k - 1, stones));
        
        // Moving k units.
        if (pos.find(stones[i] + k) != pos.end())
            ret = max(ret, go(pos[stones[i] + k], k, stones));
        
        // Moving k + 1 units.
        if (pos.find(stones[i] + k + 1) != pos.end())
            ret = max(ret, go(pos[stones[i] + k + 1], k + 1, stones));
        
        return ret;
    }

    bool canCross(vector<int>& stones) {
        // First jump must be 1 unit.
        if (stones[1] != 1)
            return false;
        
        // Mapping each stone to its position in the array.
        n = stones.size();
        for(int i = 0; i < n; i++)
            pos[stones[i]] = i;

        dp = vector<vector<int>> (n, vector<int> (2005, -1));
        return go(1, 1, stones);
    }
};