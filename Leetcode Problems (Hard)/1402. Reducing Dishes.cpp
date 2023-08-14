class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int ans = 0;
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        for(int i = 0; i < n; i++){
            int time = 1;
            int cur = time++ * satisfaction[i];
            ans = max(ans, cur);
            for(int j = i + 1; j < n; j++){
                cur += (time++ * satisfaction[j]);
                ans = max(ans, cur);
            }
        }
        return ans;
    }
};