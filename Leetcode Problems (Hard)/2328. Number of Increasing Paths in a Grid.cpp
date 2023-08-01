class Solution {
public:

    const int mod = 1e9 + 7;
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};
    int n, m;
    vector<vector<int>> mem;

    bool valid(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    int go(int x, int y, vector<vector<int>> &grid){
        int &ret = mem[x][y];
        if (~ret)
            return ret;
        ret = 1;

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (valid(nx, ny) && grid[nx][ny] > grid[x][y])
                ret += go(nx, ny, grid), ret %= mod;
        }
        return ret;
    }

    int countPaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        mem = vector<vector<int>>(n, vector<int> (m, -1));
        
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                ans += go(i, j, grid), ans %= mod;
                
        return ans;
    }
};