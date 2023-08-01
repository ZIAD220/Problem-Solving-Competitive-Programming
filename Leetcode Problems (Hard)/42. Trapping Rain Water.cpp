class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        // Building maximum suffix array where suf[i] is the maximum height found from i to n - 1.
        vector<int> suf(n + 1); 
        suf[n] = height[n - 1];
        for(int i = n - 1; i > 0; i--)
            suf[i] = max(suf[i + 1], height[i]);

        int ans = 0;
        for(int i = 0; i < n - 1; i++){
            if (!height[i])
                continue;

            int j = i + 1, sum = 0;
            int mx = suf[j];
            if (mx < height[i])
                height[i] = mx;
            
            while(height[i] > height[j]) 
                sum += height[j++];

            int traps = (j - i - 1) * min(height[j], height[i]) - sum;
            ans += traps;
            
            i = j - 1;
        }
        return ans;
    }
};