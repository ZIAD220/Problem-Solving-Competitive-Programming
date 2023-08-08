#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e6 + 5;
ll sum[N];

void sum_of_divisors(ll n)
{
    for(int i = 1; i < N; i++)
        for(int j = i; j < N; j++)
            sum[j] += i;
}