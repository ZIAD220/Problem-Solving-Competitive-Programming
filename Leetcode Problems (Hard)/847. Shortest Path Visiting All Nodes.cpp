class Solution {
public:

    int shortestPathLength(vector<vector<int>>& graph) {
        // Getting the shortest path from each node to every other node.
        int n = graph.size();
        
        if (n == 1 && graph[0].empty()) 
            return 0;
        
        // Bfs with bitmask which says whether the ith bit was visited or not.
        int ans = 1e9;
        for(int node = 0; node < n; node++)
        {
            vector<vector<bool>> vis(n, vector<bool> (1 << n));
            vis[node][1 << node] = true;
            
            queue<pair<int, int>> q;
            q.emplace(node, 1 << node);

            int length = 0;
            bool stop = false;
            while(!q.empty() && !stop)
            {
                int sz = q.size();
                while(sz-- && !stop)
                {
                    int cur = q.front().first;
                    int mask = q.front().second;
                    q.pop();
                    for(int i : graph[cur])
                    {
                        int newMask = (mask | (1 << i));
                        if (vis[i][newMask]) 
                            continue;

                        vis[i][newMask] = true;
                        if (newMask == (1 << n) - 1){
                            ans = min(ans, length + 1);
                            stop = true;
                            break;
                        }
                        q.emplace(i, newMask);
                    }
                }
                length++;
            }
        }
        return ans;       
    }
};