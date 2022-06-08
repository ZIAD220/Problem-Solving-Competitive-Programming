#pragma GCC optimize("O3")
#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl '\n'
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const ld eps = 1e-16;
vector<pair<int,string>> v;
bool ok = 1;
vector<int> ans;
int idx = 0, root = -1;

void bfs(int s)
{
    queue<pair<int,string>> q;
    q.push({s, ""});
    int cnt = 0;
    while(!q.empty() && ok)
    {
        int sz = q.size();
        cnt += sz;
        while(sz-- && ok)
        {
            int x = q.front().first;
            string y = q.front().second;
            q.pop();
            ans.push_back(x);
            pair<int,string> l, r;
            l = r = make_pair(-1, "");
            for (int i = 0; i < v.size(); i++)
            {
                int num = v[i].first;
                string str = v[i].second;
                if (str.length() == y.length() + 1)
                {
                    bool valid = 1;
                    for (int j = 0; j < y.length() && valid; j++)
                        if (str[j] != y[j]) valid = 0;
                    if (valid){
                        if (str[str.length() - 1] == 'L'){
                            if (l.first == -1)
                                {l = make_pair(num, str);}
                            else{ok = false; break;}
                        }
                        else if (r.first != -1){
                            ok = 0;
                            break;
                        }
                        else {  r = make_pair(num, str); }
                    }
                }
            }
            if (l.first != -1)
                q.push(l);
            if (r.first != -1)
                q.push(r);
        }
    }
    if (cnt != idx)
        ok = 0;
    if (!ok)
        cout << "not complete\n";
}

int main()
{
    fast
    string s;
    bool flag = 1;
    v = vector<pair<int,string>> (280);
    while(cin >> s)
    {
        if (s != "()")
        {
            int j = 0;
            while(s[j] != ',') j++;
            int x = 1;
            v[idx].first = 0;
            for (int i = j - 1; i > 0; i--)
            {
                char r = s[i];
                v[idx].first += (r - '0') * x;
                x *= 10;
            }
            v[idx].second = s.substr(j + 1, s.length() - j - 2);
            if (s.length() - j - 1 == 1) root = v[idx].first;
            idx++;
        }
        else
        {
            for (int i = 0; i < v.size(); i++){
                if (v[i].second.length() && !v[i].first){
                    root = - 1;
                    break;
                }
            }
            if (root == -1){
                cout << "not complete\n";
            }
            else{
                bfs(root);
                if (ok){
                    for (int i = 0; i < ans.size(); i++)
                        if (i != ans.size() - 1)
                            cout << ans[i] << ' ';
                        else cout << ans[i];
                    cout << '\n';
                }
            }
            idx = 0;
            v = vector<pair<int,string>> (280);
            ok = 1;
            ans.clear();
            root = -1;
        }
    }
}
