#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 105, M = 50005;

/*
 *  Key idea: Let's use dynamic-programming for solving this problem.
 *            For each coin we will consider either taking or leaving it.
 *            If we took it, we add its value to the current sum.
 *            When we reach the end, we minimize the difference between the first and second person.
 */


int n, total, a[N]; // Number of coins, the total sum of these coins and the array.
int vis[N][M], vid = 0; // Visited array and vid to handle multiple test cases.
int mem[N][M]; // Memoization array.

// DP.
int go(int i, int sum)
{
    // Base case: if we reached the end return the difference between both players.
    if (i == n)
        return abs(total - sum - sum);
    
    int &ret = mem[i][sum];
    
    // Already visited ? return it. 
    if (vis[i][sum] == vid)
        return ret;
    
    vis[i][sum] = vid; // set this state to be visited.
    
    // Two options: take or leave.
    int take = go(i + 1, sum + a[i]);
    int leave = go(i + 1, sum);
    
    return ret = min(take, leave);
}


int main()
{
    fast
    int t;
    cin >> t;
    while(t--)
    {
        total = 0;
        vid++;
        cin >> n;
        forn(i, n){
            cin >> a[i];
            total += a[i];
        }
        int ans = go(0, 0);
        cout << ans << '\n';
    }
}