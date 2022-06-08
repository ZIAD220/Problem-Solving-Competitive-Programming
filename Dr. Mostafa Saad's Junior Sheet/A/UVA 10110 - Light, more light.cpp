#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

/*
    Key Idea: We only care about the last bulb (n-th bulb) and how many numbers will
              be divisible by n.
    Let's see these two example:
    n = 9: divisors are 1 3 9 --> answer = yes.
    n = 12: divisors are 1 2 3 4 6 12 --> answer = no.
    
    Conclusion:
    If number of divisors of n is even, the answer is no. Otherwise, the answer is yes.
    
    Solution:
    How do we know if number of divisors are even or odd ?
    If n is perfect square (like 1, 4, 9, 16, 25, ...), the number of divisors are odd ;)
*/



int main()
{
    fast
    ll n;
    while(cin >> n && n > 0)
    {
        ll sqr = sqrtl(n);
        if (sqr * sqr == n)
            cout << "yes\n";
        else cout << "no\n";
    }
}