#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

/*
 *  Key idea: Try everything using backtracking.
 *            For every number we will have three options: +, -, *.
 */

int a[5]; // 5-Tuples.
bool can = false;  // Possible or Impossible.
bool vis[5]; // We need to choose the number only once, so we use visited array.

void go(int num)
{
    // Base case: if num is 23 and all numbers are visited.
    if (num == 23){
        if (vis[0] & vis[1] & vis[2] & vis[3] & vis[4]){
            can = true;
            return;
        }
    }

    for(int i = 0; i < 5; i++){
        // If this number was used, leave it.
        if (vis[i]) continue;

        vis[i] = true;
        go(num + a[i]);
        if (can) return; // Just to make it faster.
        go(num * a[i]);
        if (can) return;
        go(num - a[i]);
        vis[i] = false;
    }
}

int main()
{
    fast
    while(cin >> a[0] && a[0] > 0)
    {
        for(int i = 1; i < 5; i++)
            cin >> a[i];

        can = false;

        // For every number we try taking it as the starting value.
        for(int i = 0; i < 5; i++){
            vis[i] = true;
            go(a[i]);
            vis[i] = false;
        }

        cout << (can ? "Possible\n" : "Impossible\n");

        for(int i = 0; i < 5; i++)
            vis[i] = false;
    }
}