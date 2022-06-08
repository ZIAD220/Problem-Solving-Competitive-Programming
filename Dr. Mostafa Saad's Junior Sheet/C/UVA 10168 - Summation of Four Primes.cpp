#pragma GCC optimize("O3")
#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const ld eps = 1e-16;
const ll mod = 1e9 + 7;

bool isprime[10000005];
vector<ll> v;
ll bs(ll n, ll k)
{
    ll l = 0, r = v.size() - 1;
    while (l < r)
    {
        ll mid = l + (r - l + 1) / 2;
        if (v[mid] + k > n)
            r = mid - 1;
        else l = mid;
    }
    return v[l];
}

int main()
{
    fast
    memset(isprime, true, sizeof(isprime));
    isprime[0] = isprime[1] = false;
    for (ll i = 2; i * i <= 10000000; i++)
    {
        if (isprime[i]){
            for(ll j = i * 2; j <= 10000000; j += i)
                isprime[j] = false;
        }
    }
    for (ll i = 2; i <= 10000000; i++)
        if (isprime[i])
            v.push_back(i);
    ll n;
    while(cin >> n)
    {
        if (n < 8){
            cout << "Impossible.\n";
            continue;
        }
        vector<ll> a(4);
        a[0] = a[1] = a[2] = a[3] = 2;
        ll sum = 0;
        for (int i = 0; i < 4; i++)
        {
            sum = a[0] + a[1] + a[2] + a[3];
            ll rest = sum - a[i];
            if (sum == n) break;
            ll x = bs(n, rest);
            sum -= a[i];
            a[i] = x;
            sum += a[i];
            if (sum == n) break;
        }
        if (sum != n){
            cout << "Impossible.\n" << endl;
            continue;
        }
        for (int i = 0; i < 4; i++)
            cout << a[i] << ' ';
        cout << endl;
    }
}