int dx[] = {-1, +1, +0, +0, +1, +1, -1, -1};
int dy[] = {+0, +0, +1, -1, +1, -1, +1, -1};

const int N = 1e3 + 5;
int grid[N][N], dis[N][N], n, m;

bool valid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(int sx, int sy)
{
    // Initializing array (dis) where dis[i][j] is the shortest distance between the start point (sx, sy) and (i, j).
    memset(dis, '?', sizeof(dis)); // '?' is a very large number.
    dis[sx][sy] = 0;

    deque<pair<int,int>> q;
    q.emplace_back(sx, sy);
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop_front();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (valid(nx, ny))
            {
                int w = (grid[x][y] != grid[nx][ny]); // Weight.

                // Relaxation.
                if (dis[x][y] + w < dis[nx][ny])
                {
                    dis[nx][ny] = dis[x][y] + w;
                    if (w)
                        q.emplace_back(nx, ny);
                    else q.emplace_front(nx, ny);
                }
            }
        }
    }
}