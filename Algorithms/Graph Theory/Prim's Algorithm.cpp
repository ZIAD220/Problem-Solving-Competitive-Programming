#include <bits/stdc++.h>
#define sz(v) ((int)((v).size()))
using namespace std;

struct Edge{
    int from, to, w;
    Edge(int from, int to, int w): from(from), to(to), w(w) {}
    bool operator<(const Edge &rhs) const{
        return this->w < rhs.w;
    }
};

vector<vector<pair<int, int>>> adj;

// Returns the total cost and the path.
pair<int, vector<Edge>> prim(int start){
    vector<bool> vis(sz(adj));
    vis[start] = true;

    vector<Edge> path;

    priority_queue<Edge> pq;
    pq.emplace(-1, start, 0);

    int minCost = 0;
    while(!pq.empty())
    {
        Edge e = pq.top();
        pq.pop();

        if (vis[e.to])
            continue;

        vis[e.to] = true;
        minCost += e.w;

        if (e.from != -1)
            path.push_back(e);

        for(auto &i : adj[e.to])
        {
            if (vis[i.first])
                continue;

            pq.emplace(e.to, i.first, i.second);
        }
    }

    return {minCost, path};
}