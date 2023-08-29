class Solution {
public:

    const long long mod = 1e9 + 7;

    long long fp(long long base, long long exp){
        if (exp == 0) return 1;
        long long ans = fp(base, exp / 2);
        if (exp % 2 == 0) return (ans * ans) % mod;
        else return (((ans * ans)% mod) * base)% mod;
    }


    long long ncr(int n, int r){
        long long ans = 1, k = 1;
        for (int i = n; i > n - r; i--) {
            ans = (ans * i) % mod;
            ans = (ans * fp(k, mod - 2))%mod;
            k++;
        }
        return ans;
    }


    long long dfs(vector<int> nums){
        int n = nums.size();
        if (n < 3)
            return 1;
       
        vector<int> left, right;
        for(int i = 1; i < n; i++)
            nums[i] < nums[0] ? left.push_back(nums[i]) : right.push_back(nums[i]);
       
        long long leftSubtree = dfs(left) % mod;
        long long rightSubtree = dfs(right) % mod;
        long long total = ncr(n - 1, left.size()) % mod;

        long long ans = leftSubtree * rightSubtree % mod;
        ans *= total, ans %= mod;
        return ans;
    }

    int numOfWays(vector<int>& nums) {
        return (dfs(nums) - 1) % mod;
    }
};