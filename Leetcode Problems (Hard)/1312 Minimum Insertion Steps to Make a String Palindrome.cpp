const int N = 505;
int mem[N][N];

class Solution {
public:

    int n;

    int go(int i, int j, string &s){
        if (i >= j || i == n || j == -1)
            return 0;
        
        int &ret = mem[i][j];
        if (~ret)
            return ret;
        
        ret = 1e9;
        if (s[i] == s[j])
            ret = go(i + 1, j - 1, s);
        
        return ret = min({ret, 1 + go(i + 1, j, s), 1 + go(i, j - 1, s)});
    }

    int minInsertions(string s) {
        n = s.length();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                mem[i][j] = -1;
        return go(0, n - 1, s); 
    }
};