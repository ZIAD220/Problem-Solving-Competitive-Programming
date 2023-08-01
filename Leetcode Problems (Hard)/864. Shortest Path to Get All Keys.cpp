const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

class Solution {
public:

    int n, m;

    bool valid(int x, int y, vector<string> &grid){
        return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#';
    }

    int shortestPathAllKeys(vector<string>& grid) {
        n = grid.size();
        m = grid[0].size();
        int sx, sy;
        int keys = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if (grid[i][j] == '@')
                    sx = i, sy = j;
                keys += (grid[i][j] >= 'a' && grid[i][j] <= 'z');
            }
        }
        
        map<pair<pair<int, int>, int>, bool> vis;
        queue<pair<pair<int, int>, int>> q;
        q.push({{sx, sy}, 0});
        vis[{{sx, sy}, 0}] = true;
        int ans = 0;

        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto cur = q.front();
                q.pop();
                int x = cur.first.first;
                int y = cur.first.second;
                int mask = cur.second;
                
                if (mask == (1 << keys) - 1)
                    return ans;

                for(int i = 0; i < 4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (!valid(nx, ny, grid)) continue;
                    
                    char ch = grid[nx][ny];

                    // Getting a key.
                    if (ch >= 'a' && ch <= 'z'){
                        int newMask = mask | (1 << (ch - 'a'));
                        if (vis.find({{nx, ny}, newMask}) == vis.end()){
                            vis[{{nx, ny}, newMask}] = true;
                            q.push({{nx, ny}, newMask});
                        }
                    }
                    // Unlocking a lock.
                    else if (ch >= 'A' && ch <= 'Z'){
                        if (mask & (1 << (ch - 'A')) && vis.find({{nx, ny}, mask}) == vis.end()){
                            vis[{{nx, ny}, mask}] = true;
                            q.push({{nx, ny}, mask});
                        }
                    }
                    // Empty cell.
                    else if (vis.find({{nx, ny}, mask}) == vis.end()) {
                        vis[{{nx, ny}, mask}] = true;
                        q.push({{nx, ny}, mask});
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};