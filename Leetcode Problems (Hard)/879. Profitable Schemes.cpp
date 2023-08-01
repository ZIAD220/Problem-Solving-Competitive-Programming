const int N = 105, mod = 1e9 + 7;
int vis[N][N][N], vid = 0;
int mem[N][N][N];

class Solution {
public:

    int m; // Number of groups.
    int need; // Minimum profit.

    int go(int i, int sum, int rem, vector<int> &group, vector<int> &profit){
        if (i == m || rem == 0)
            return sum >= need;
        
        int &ret = mem[i][sum][rem];
        if (vis[i][sum][rem] == vid)
            return ret;
        vis[i][sum][rem] = vid;

        ret = 0;

        int take = 0;
        if (rem >= group[i]){
            int nextSum = min(sum + profit[i], need);
            int nextRem = rem - group[i];
            take = go(i + 1, nextSum, nextRem, group, profit);
        }

        int leave = go(i + 1, sum, rem, group, profit);

        ret = ((take % mod) + (leave % mod)) % mod;
        return ret;
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        m = group.size();
        need = minProfit;
        vid++;

        return go(0, 0, n, group, profit);
    }
};