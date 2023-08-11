int n;
vector<vector<pair<int, int>>> adj;

vector<int> bfs(int start)
{
    // Initializing array (dis) where dis[i] is the shortest distance between the start node and i-th node.
    vector<int> dis(n, 1e9);
    dis[start] = 0;

    deque<int> q;
    q.push_front(start);

    while (!q.empty())
    {
        int v = q.front();
        q.pop_front();

        for (auto &[u, w] : adj[v])
        {
            // Relaxation.
            if (dis[v] + w < dis[u])
            {
                dis[u] = dis[v] + w;
                if (w == 1)
                    q.push_back(u);
                else
                    q.push_front(u);
            }
        }
    }

    return dis;
}