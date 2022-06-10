#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) ((ll)((v).size()))
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e2 + 5;

/*
    Key idea: Use backtracking to solve the problem.
              For each node, we will try coloring it black and recurse from the next node (node + 1).
              But, we need pruning condition in order to improve the complexity.
              If We know that we had reached a better solution (more maximum black nodes), then we don't
              need to continue.

    Note: I got two Wrong Answer because of the extra space in the output :(.
 */



int t, n, m;
vector<int> best; // Vector containing the best black nodes.
vector<int> cur; // Current black nodes.
vector<vector<int>> adj; // Adjacency Matrix.
int clr[105]; // Color : 0->White, 1->Black.

void go(int idx)
{
    // Base case: If current black nodes are more than the best, assign the best to cur.
    if (sz(cur) > sz(best))
        best = cur;

    // Pruning.
    if (sz(best) + n - idx <= sz(best))
        return;

    for(int i = idx + 1; i <= n; i++)
    {
        // Checking if we can color this node black.
        bool canColor = true;
        for(int node : adj[i])
            if (clr[node] == 1){
                canColor = false;
                break;
            }

        if (!canColor) continue;

        // Do.
        clr[i] = 1;
        cur.push_back(i);

        // Recurse.
        go(i);

        // Undo.
        clr[i] = 0;
        cur.pop_back();
    }
}

int main()
{
    fast
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        adj = vector<vector<int>> (n + 1);
        forn(i, m)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        go(0);
        cout << sz(best) << '\n';
        forn(i, sz(best)){
            cout << best[i];
            if (i < sz(best) - 1)
                cout << ' ';
        }
        cout << '\n';
        best.clear();
        cur.clear();
    }
}