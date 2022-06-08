#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e5 + 5;

/*
    Key idea is to simulate the problem.
    Loop on the mod value and keep tracking of the sum so far.
    If one of the mods repeats again, then this is a bad choice.
    If we visited all values from 0 to mod - 1, the answer is good choice.
*/


bool vis[N]; // Visited array to check if the mods are repeated or not.

int main()
{
    fast
    int step, mod;
    while(cin >> step >> mod)
    {
        int sum = 0, cnt = 0;
        for(int i = 0; i < mod; i++)
        {
            if (vis[sum % mod])
                break;
            vis[sum % mod] = true;
            sum = (sum % mod) + step;
            cnt++;
        }

        cout << setw(10) << step << setw(10) << mod << "    ";
        if (cnt == mod)
            cout << "Good Choice\n\n";
        else cout << "Bad Choice\n\n";

        // Resetting visited array again.
        for(int i = 0; i < mod; i++)
            vis[i] = false;
    }
}