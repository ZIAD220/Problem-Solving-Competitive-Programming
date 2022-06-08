#pragma GCC optimize("O3")
#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const ld eps = 1e-16;
const ll mod = 1e9 + 7;

char a[200][200];
int t, n, m;
map<pair<int,int>, int> mp;

bool valid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m && !mp[{x,y}];
}

vector<vector<int>> bfs()
{
    vector<vector<int>> len(n, vector<int> (m));
    queue<pair<int,int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (a[i][j] == '1')q.push({i,j}), len[i][j] = 0, mp[{i,j}]++;
    }
    ll dep = 0;
    bool ok = 1;
    while(!q.empty() && ok)
    {
        int sz = q.size();
        while(sz-- && ok){
            int x = q.front().first;
            int y = q.front().second; q.pop();
            if (valid(x + 1, y)) q.push({x+1, y}), len[x + 1][y] = dep + 1, mp[{x + 1,y}]++;;
            if (valid(x, y + 1)) q.push({x, y + 1}), len[x][y + 1] = dep + 1, mp[{x,y + 1}]++;;
            if (valid(x - 1, y)) q.push({x-1, y}), len[x - 1][y] = dep + 1, mp[{x-1,y}]++;;
            if (valid(x, y - 1)) q.push({x, y - 1}), len[x][y-1] = dep + 1, mp[{x,y - 1}]++;;
        }
        dep++;
    }
    return len;
}

int main()
{
    fast
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        vector<vector<int>> ans = bfs();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << ans[i][j] << ' ';
            cout << '\n';
        }
        mp.clear();
    }
}
