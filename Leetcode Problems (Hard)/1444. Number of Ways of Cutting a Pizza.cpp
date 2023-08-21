int mem[10][50][50];
class Solution {
public:

    int n, m, K;
    int mod = 1e9 + 7;
    vector<vector<int>> pre;

    int sum_range(int i, int j, int k, int l){
        i++, j++, k++, l++;
        return pre[k][l] - pre[k][j - 1] - pre[i - 1][l] + pre[i - 1][j - 1];
    }

    int go(int cuts, int x, int y){
        if (x == n || y == m)
            return 0;
        
        if (cuts == K - 1)
            return 1;

        int &ret = mem[cuts][x][y];
        if (~ret)
            return ret;
        ret = 0;

        for(int i = x; i < n - 1; i++)
            if (sum_range(x, y, i, m - 1) && sum_range(i + 1, y, n - 1, m - 1))
                ret += go(cuts + 1, i + 1, y), ret %= mod;
        
        for(int i = y; i < m - 1; i++)
            if (sum_range(x, y, n - 1, i) && sum_range(x, i + 1, n - 1, m - 1))
                ret += go(cuts + 1, x, i + 1), ret %= mod;

        return ret;
    }

    int ways(vector<string>& pizza, int k) {
        n = pizza.size();
        m = pizza[0].size();
        K = k;

        if (k == 1){
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    if (pizza[i][j] == 'A')
                        return 1;
            return 0;
        }

        memset(mem, -1, sizeof(mem));
        
        pre = vector<vector<int>> (n + 1, vector<int> (m + 1));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                pre[i + 1][j + 1] = pizza[i][j] == 'A';
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                pre[i][j] += pre[i][j - 1];
        for(int j = 1; j <= m; j++)
            for(int i = 1; i <= n; i++)
                pre[i][j] += pre[i - 1][j];
        return go(0, 0, 0);
    }
};