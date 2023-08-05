class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        map<int, set<int>> adj;
        for(int i = 0; i < n; i++)
            adj[arr[i]].insert(i);

        vector<bool> vis(n);
        vis[0] = true;
        queue<int> q;
        q.push(0);
        int dep = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int cur = q.front(); q.pop();
                cout << cur << endl;
                if (cur == n - 1)
                    return dep;
                if (cur + 1 < n && !vis[cur + 1]){
                    vis[cur + 1] = true;
                    q.push(cur + 1);
                }
                if (cur - 1 > 0 && !vis[cur - 1]){
                    vis[cur - 1] = true;
                    q.push(cur - 1);
                }
                for(int x : adj[arr[cur]])
                    if (!vis[x]){
                        vis[x] = true;
                        q.push(x);
                    }
                adj[arr[cur]].clear();
            }
            dep++;
        }
        return dep;
    }
};