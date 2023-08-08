#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e6 + 5;
int comp[N]; // Says the smallest prime for each number.

void modified_sieve()
{
    iota(comp, comp + N, 0);
    comp[0] = comp[1] = -1;
    for (ll i = 2; i <= N / i; i++)
        if (comp[i] == i)
            for (ll j = i * i; j <= N; j += i)
                if (comp[j] == j)
                    comp[j] = i;
}

ll fast_power (ll n, ll k)
{
    if (k==0)
        return 1;
    ll ans = fast_power(n, k/2);
    ans = ((ans ) * (ans)) ;
    if (k&1)
        ans = ((ans ) * (n )) ;
    return ans ;
}

ll sum_of_divisors(ll n)
{
    ll sum = 1;
    while(n > 1)
    {
        ll cur = comp[n], cnt = 0;
        while(n % cur == 0)
            n /= cur, cnt++;
        sum *= (fast_power(cur, cnt + 1) - 1) / (cur - 1);
    }
    return sum;
}