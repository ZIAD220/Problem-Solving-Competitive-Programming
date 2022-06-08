#pragma GCC optimize("O3")
#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl '\n'
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const ld eps = 1e-16;

int p[100005], sz[100005];

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

int main()
{
    fast
    int t,f;
    cin >> t;
    while(t--)
    {
        cin >> f;
        for (int i = 0; i <= 100003; i++)
            p[i] = i, sz[i] = 1;
        map<string,int> mp;
        int num = 1;
        for (int i = 0; i < f; i++)
        {
            string a,b;
            cin >> a >> b;
            if (!mp[a])
                mp[a] = num, num++;
            if (!mp[b])
                mp[b] = num, num++;
            if (find_parent(mp[a]) != find_parent(mp[b]))
                dsu(mp[a], mp[b]);
            int par = find_parent(mp[a]);
            cout << sz[par] << '\n';
        }
    }
}
