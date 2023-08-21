class Solution {
public:

    vector<bool> inStk, vis;
 
    vector<int> itemsOrder, groupsOrder;

    vector<set<int>> beforeGroups;

    // Depth-first search to detect if there's a cycle between items.
    bool dfs(int node, vector<int> &group, vector<vector<int>> &adj){
        inStk[node] = true;

        for(int i : adj[node])
        {
            if (group[node] != group[i])
                beforeGroups[group[node]].insert(group[i]);

            if (inStk[i] && vis[i])
                return true;

            if (vis[i]) continue;

            
            vis[i] = true;
            if (dfs(i, group, adj))
                return true;
        }
        
        itemsOrder.push_back(node);
        inStk[node] = false;
        return false;
    }    

    // Depth-first search to detect if there's a cycle between groups.
    bool dfs(int node, vector<set<int>> &adj){
        inStk[node] = true;

        for(int i : adj[node])
        {
            if (inStk[i] && vis[i])
                return true;

            if (vis[i]) continue;

            vis[i] = true;
            if (dfs(i, adj))
                return true;
        }
        
        groupsOrder.push_back(node);
        inStk[node] = false;
        return false;
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // Let's assume that the each item that doesn't belong to any group is a new different group.
        for(int i = 0; i < n; i++)
            if (group[i] == -1)
                group[i] = m++;
        
        // Detecting if there's a cycle between items.
        inStk = vis = vector<bool> (n);
        beforeGroups = vector<set<int>> (m);
        for(int i = 0; i < n; i++){
            if (vis[i]) continue;

            vis[i] = true;
            if (dfs(i, group, beforeItems))
                return vector<int> ();
        }

        for(int i = 0; i < m; i++){
            for(int j : beforeGroups[i])
                cout << j << ' ';
            cout << endl;
        }

        // Detecting if there's a cycle between groups.
        inStk = vis = vector<bool> (m);
        for(int i = 0; i < m; i++){
            if (vis[i]) continue;

            vis[i] = true;
            if (dfs(i, beforeGroups))
                return vector<int> ();
        }

        // Adjacency list where adj[i] contains indicies of items of group i.
        vector<vector<int>> adj(m); 
        for(int i = 0; i < n; i++)
        {
            int g = group[itemsOrder[i]];
            adj[g].push_back(i);
        }

        vector<int> ans;
        for(int i : groupsOrder)
            for(int j : adj[i])
                ans.push_back(itemsOrder[j]);
    
        // Checking if the answer is correct.
        vector<bool> came(n);
        for(int i : ans)
        {
            for(int j : beforeItems[i])
                if (!came[j])
                    return vector<int> ();
            came[i] = true;
        }

        return ans;
    }
};