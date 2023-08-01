class Solution {
public:

    const int mod = 1e9 + 7;
    int dp[100][201], n;

    int go(int i, int fuel, int finish, vector<int> &locations){
        if (!fuel)
            return i == finish;
        
        int &ret = dp[i][fuel];
        if (~ret)
            return ret;
        
        ret = (i == finish);
        for(int j = 0; j < n; j++){
            int distance = abs(locations[i] - locations[j]);
            if (i == j || distance > fuel) continue;
            ret += go(j, fuel - distance, finish, locations);
            ret %= mod;
        }
        return ret;
    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        n = locations.size();
        memset(dp, -1, sizeof(dp));
        return go(start, fuel, finish, locations);
    }
};