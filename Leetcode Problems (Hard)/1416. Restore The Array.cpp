const int N = 1e5 + 5, mod = 1e9 + 7;
int mem[N];

class Solution {
public:

    int n;

    int go(int i, string &s, int k){
        if (i == n)
            return 1;

        if (s[i] == '0')
            return 0;
        
        int &ret = mem[i];
        if (~ret)
            return ret;
        
        ret = 0;
        string cur;
        for(int j = i; j < n; j++){
            cur.push_back(s[j]);
            long long num = stoll(cur);
            if (num > k)
                break;
            ret += go(j + 1, s, k);
            ret %= mod;
        }
        return ret;
    }

    int numberOfArrays(string s, int k) {
        n = s.length();
        for(int i = 0; i < n; i++)
            mem[i] = -1;
        
        return go(0, s, k);
    }
};