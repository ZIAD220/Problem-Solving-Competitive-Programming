class Solution {
public:

    static const int N = 501;
    int mem[N][N][2];
    bool vis[N][N][2];

    int dp(int i, int j, bool isEmpty, vector<int>& nums1, vector<int>& nums2){
        int size1 = nums1.size();
        int size2 = nums2.size();
        if (i == size1 || j == size2)
            return !isEmpty ? 0 : -1e9;

        int &ret = mem[i][j][isEmpty];
        if (vis[i][j][isEmpty])
            return ret;

        vis[i][j][isEmpty] = true;

        int leaveI = -1e9, leaveJ = -1e9, take = -1e9;
        if (i + 1 <= size1)
            leaveI = dp(i + 1, j, isEmpty, nums1, nums2);
       
        if (j + 1 <= size2)
            leaveJ = dp(i, j + 1, isEmpty, nums1, nums2);
       
        if (i + 1 <= size1 && j + 1 <= size2)
            take = dp(i + 1, j + 1, false, nums1, nums2) + nums1[i] * nums2[j];
        
        return ret = max({leaveI, leaveJ, take});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        /*
            dp[i][j] -> 
            i is the current index of nums1
            j is the current index of nums2
            leaveI = dp[i + 1][j];
            leaveJ = dp[i][j + 1];
            take = dp[i + 1][j + 1] + nums1[i] * nums2[j];
        */
        for(int i = 0; i < (int)nums1.size(); i++)
            for(int j = 0; j < (int)nums2.size(); j++)
                vis[i][j][0] = vis[i][j][1] = false;
        return dp(0, 0, true, nums1, nums2);
    }
};