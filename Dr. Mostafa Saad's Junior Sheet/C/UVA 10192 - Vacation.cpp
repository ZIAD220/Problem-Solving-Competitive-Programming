#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define sz(v) ((ll)((v).size()))
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

/*
 *  Key idea: This is a famous DP problem called longest increasing subsequence.
 *            We just use the algorithm and memoize the answer each time.
 */

string a, b;
int n, m, mem[105][105], vis[105][105], vid = 0;

int go(int i, int j)
{
    if (i == n || j == m)
        return 0;
    
    if (vis[i][j] == vid)
        return mem[i][j];
    
    vis[i][j] = vid;
    
    if (a[i] == b[j])
        return mem[i][j] = 1 + go(i + 1, j + 1);
    
    return mem[i][j] = max(go(i + 1, j), go(i, j + 1));
}

int main()
{
    fast
    int t = 1;
    while(getline(cin, a) && a != "#" && getline(cin, b))
    {
        vid++;
        n = sz(a), m = sz(b);
        int ans = go(0, 0);
        cout << "Case #" << t <<": you can visit at most " << ans << " cities.\n";
        t++;
    }
}