#include <bits/stdc++.h>
#define sz(v) ((int)((v).size()))
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define show(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
template <typename T>
ostream& operator <<(ostream& out, const vector<T>& v){forn(i,sz(v)) out<<v[i]<<' ';return out;}

/*
 * Dijkstra is used in non -ve weighted graph
 */

vector<vector<pair<int, ll>>> adj;
vector<ll> dis; // dis[i] is the shortest distance form start node to node i.
vector<int> par; // par[i] is the parent of node i. We use this to build the path from start to node n.

// Function that uses dijkstra to calculate the shortest path from start node to node n.
vector<int> dijkstra(int start, int end)
{
    dis = vector<ll> (sz(adj), 1e17);
    dis[start] = 0;

    par = vector<int> (sz(adj), -1);

    priority_queue<pair<ll,ll>> pq;
    pq.emplace(0, start);

    while(!pq.empty()){
        auto tp = pq.top();
        pq.pop();
        ll u = tp.second, d = tp.first;
        if (d != dis[u]) continue;
        for (auto &[v, cost]: adj[u]){
            if (dis[u] + cost < dis[v]){
                par[v] = u;
                dis[v] = dis[u] + cost;
                pq.emplace(dis[v], v);
            }
        }
    }

    // If we couldn't reach end node, return -1;
    if (dis[end] == (ll)1e17)
        return {-1};

    // Building path using par array.
    vector<int> path;
    path.push_back(end);
    int cur = end;
    while(par[cur] != -1){
        path.push_back(par[cur]);
        cur = par[cur];
    }

    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    int n, m;
    cin >> n >> m;
    adj = vector<vector<pair<int, ll>>> (n + 1);
    for (int i = 0; i < m; i++){
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vector<int> ans = dijkstra(1, n);

    if (ans[0] != -1)
        cout << ans << '\n';
    else cout << "Not reachable.";
}
