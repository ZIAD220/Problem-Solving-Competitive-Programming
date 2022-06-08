#pragma GCC optimize("O3")
#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl '\n'
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const ld eps = 1e-16;

int p[505], sz[505];

ll find_parent(int v){
    if (p[v] == v)
        return v;
    return p[v] = find_parent(p[v]);
}

void dsu(int a, int b){
    a = find_parent(a);
    b = find_parent(b);
    if (sz[a] < sz[b])
        swap(a,b);
    p[b] = a;
    sz[a] += sz[b];
}

struct edge{
    ll a,b,c;
    bool operator <(const edge &e){
        return c < e.c;
    }
};

int main()
{
    fast
    int t,n,s;
    cin >> t;
    while(t--)
    {
        cin >> s >> n;
        for (int i = 0; i <= n; i++)
            p[i] = i, sz[i] = 1;
        vector<pair<ll,ll>> v(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> v[i].first >> v[i].second;
        vector <edge> edges;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                ll x1 = v[i].first, x2 = v[j].first;
                ll y1 = v[i].second, y2 = v[j].second;
                ll d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
                edges.push_back({i,j,d});
            }
        }
        sort(edges.begin(), edges.end());
        vector<ll> len;
        for (int i = 0; i < edges.size(); i++)
        {
            if (find_parent(edges[i].a) != find_parent(edges[i].b)){
                dsu(edges[i].a, edges[i].b);
                len.push_back(edges[i].c);
            }
        }
        cout << fixed << setprecision(2) << sqrt(len[n - s - 1]) << '\n';
    }
}
