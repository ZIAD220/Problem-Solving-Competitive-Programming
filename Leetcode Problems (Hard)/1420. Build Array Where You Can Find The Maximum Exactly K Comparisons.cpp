class Solution {
public:

    static const int N = 51, M = 101; 
    static const int mod = 1e9 + 7;
    int dp[N][N][M];

    int go(int idx, int cost, int maxVal, int n, int m, int k){
        if (idx == n)
            return cost == k;
        
        if (cost > k)
            return 0;
        
        int &ret = dp[idx][cost][maxVal];
        if (ret != -1)
            return ret;

        ret = 0;

        for(int i = 1; i <= maxVal; i++){
            ret += go(idx + 1, cost, maxVal, n, m, k);
            ret %= mod;
        }

        for(int i = maxVal + 1; i <= m; i++){
            ret += go(idx + 1, cost + 1, i, n, m, k);
            ret %= mod;
        }

        return ret;
    }

    int numOfArrays(int n, int m, int k) {
        memset(dp, -1, sizeof(dp));
        int ans = go(0, 0, 0, n, m, k);
        return ans;
    }
};