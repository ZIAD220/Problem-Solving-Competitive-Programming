#pragma GCC optimize("O3")
#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const ld eps = 1e-16;
const ll mod = 1e9 + 7;

string a[1004][20000];
ull ans[1004][20000];
map<string, int> mp;
ull dfs(int i, int j)
{
    if (ans[i][j])
        return ans[i][j];
    if (a[i][j][0] != '=')
        return ans[i][j] = stoll(a[i][j]);
    ull sum = 0;
    int k = 1;
    while (k < a[i][j].length()){
        string s = "";
        while(1){
            char c = a[i][j][k];
            if (c >= '1' && c <= '9') break;
            s.push_back(c), k++;
        }
        int y = mp[s];
        s = "";
        while(k < a[i][j].length()){
            char c = a[i][j][k];
            if (c == '+'){k++; break;}
            s.push_back(c), k++;
        }
        ll x = stoll(s);
        sum += dfs(x, y);
    }
    return ans[i][j] = sum;
}

int main()
{
    fast
    int i = 1, cnt = 1;
    while(cnt <= 3)
    {
        string s = "";
        for (int j = 0; j < cnt; j++)
            s.push_back('A');
        if (cnt == 1)
        {
            while(s[0] <= 'Z')
                mp[s] = i, i++, s[0]++;
        }
        else if (cnt == 2)
        {
            while(s[0] <= 'Z'){
                s[1] = 'A';
                while(s[1] <= 'Z')
                    mp[s] = i, i++, s[1]++;
                s[0]++;
            }
        }
        else{
            while(s[0] <= 'Z'){
                s[1] = 'A';
                while(s[1] <= 'Z'){
                    s[2] = 'A';
                    while(s[2] <= 'Z')
                        mp[s] = i, i++, s[2]++;
                    s[1]++;
                }
                s[0]++;
            }
        }
        cnt++;
    }
    int t,n,m;
    cin >> t;
    while(t--)
    {
        cin >> m >> n;
        for (i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cin >> a[i][j];
                ans[i][j] = 0;
            }
        }
        for (i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++){
                ull d = dfs(i,j);
                if (j != m)
                    cout << d << ' ';
                else cout << d;
            }
            cout << '\n';
        }
    }
}
