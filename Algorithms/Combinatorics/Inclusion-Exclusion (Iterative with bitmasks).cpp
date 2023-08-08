#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
 * Let's solve a famous problem.
 * How many numbers between l and r are divisible by 2, 3, 5, or 7?
 * We can observe that there are numbers that are both divisible by 2 and 3 at the same time (like 6 or 12).
 * These numbers will get counted multiple times not only once. So, we need to exclude these intersections.
 * Algorithm:
 *      1- Loop on all subsets(masks).
 *      2- Compute each intersection.
 *      3- If the intersection size is odd, we include it.
 *      4- If the intersection size is even, we exclude it.
 */

ll GCD(ll a, ll b)
{
    if (!b)
        return a;
    return GCD(b, a % b);
}

ll LCM(ll a, ll b)
{
    ll ret = (a * b) / GCD(a, b);
    return ret;
}

ll inclusionExclusion(ll range, vector<int> &items){
    const int n = items.size();
    const int max_size = 1 << n;
    ll ans = 0;
    for(int mask = 1; mask < max_size; mask++){
        // The intersection can be found by calculating the least common multiple of the chosen items.

        ll lcm = 1, subset_size = 0;
        for(int bit = 0; bit < n; bit++)
            if (mask & (1 << bit)){
                subset_size++;
                lcm = LCM(lcm, items[bit]);
            }

        // If the subset_size is odd we add it, otherwise we subtract it.
        ll sign = subset_size & 1 ? 1 : -1;

        ans += sign * range / lcm;
    }

    return ans;
}

int main() {
    int l = 1, r = 100;
    vector<int> items = {2, 3, 5, 7};
    cout << inclusionExclusion(r, items) - inclusionExclusion(l - 1, items) << '\n';
}