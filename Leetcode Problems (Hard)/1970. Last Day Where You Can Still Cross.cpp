int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

class Solution {
public:

    vector<vector<int>> changes; // Time at which cell (i, j) changes to 1.
    int n, m;

    bool valid(int x, int y, int day, vector<vector<bool>> &vis){
        return x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && changes[x][y] > day;
    }

    // Function to check whether it is possible to move from top to bottom at the given day.
    bool can(int day){
        // Making bfs from top to bottom igonring land cells made from the first day till the current day.
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m));
        for(int i = 0; i < m; i++)
            if (changes[0][i] > day){
                q.emplace(0, i);
                vis[0][i] = true;
            }

        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if (x == n - 1)
                    return true;
                
                for(int i = 0; i < 4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (valid(nx, ny, day, vis)){
                        vis[nx][ny] = true;
                        q.emplace(nx, ny);
                    }
                }
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        changes = vector<vector<int>> (row, vector<int> (col, 1e9));
        n = row;
        m = col;

        for(int i = 0; i < (int)cells.size(); i++){
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            changes[r][c] = i + 1;
        }

        // Binary search on the answer.
        int l = 0, r = cells.size() - 1, ans = 0;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if (can(mid))
                ans = mid, l = mid + 1;
            else r = mid - 1;
        }
        return ans;
    }
};