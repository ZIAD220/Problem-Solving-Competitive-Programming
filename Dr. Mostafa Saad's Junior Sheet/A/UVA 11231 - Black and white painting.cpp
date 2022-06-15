#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e2 + 5;

/*
 *  Key idea:
 *      If we look at chess board, we will notice that the rows keep alternating.
 *      If a row ends with white cell, the next row will end with black cell and so on.
 *      So, if we know the number of valid chess board in a column ending with black cell,
 *      we will multiply it by the number of rows ending with black cell.
 *      The same operation is applied for the rows ending with white cell.
 *      But we need to subtract 8 when calculating these values; because chess boards are 8x8.
 */

int main()
{
    fast
    ll n, m, c;
    while(cin >> n >> m >> c && (n || m || c))
    {
        ll cnt1; // Ending with white.
        ll cnt2; // Ending with black.
        ll ans = 0;

        // Two different cases: odd and even.
        if (m & 1){
            cnt1 = (m - 8 + 1) / 2;
            cnt2 = (m - 8 + 1) / 2;
        }
        else{
            cnt1 = (m - 8) / 2 + 1;
            cnt2 = (m - 8) / 2;
            if (!c)
                swap(cnt1, cnt2);
        }

        // Multiplying.
        ans += cnt1 * ((n - 8 + 2) / 2);
        ans += cnt2 * ((n - 8 + 1) / 2);

        cout << ans << '\n';
    }
}