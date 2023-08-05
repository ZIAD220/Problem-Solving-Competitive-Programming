class Solution {
public:

    unordered_map<string, int> mp;
    vector<vector<int>> dp;
    vector<int> ans;
    int n;

    int go(int i, int mask, vector<vector<string>> &people){
        if (i == (int)people.size())
            return mask != (1 << n) - 1 ? 1e9 : 0;
        
        int &ret = dp[i][mask];
        if (~ret)
            return ret;
        
        int new_mask = mask;
        for(string skill : people[i])
            if (mp.find(skill) != mp.end())
                new_mask |= (1 << mp[skill]);
        
        int leave = go(i + 1, mask, people);
        int take = 1 + go(i + 1, new_mask, people);

        return ret = min(take, leave);
    }

    void getAnswer(int i, int mask, vector<vector<string>> &people){
        if (i == (int)people.size())
            return;
        
        int new_mask = mask;
        for(string skill : people[i])
            if (mp.find(skill) != mp.end())
                new_mask |= (1 << mp[skill]);
        
        int leave = go(i + 1, mask, people);
        int take = 1 + go(i + 1, new_mask, people);
        int &ret = dp[i][mask];
        
        if (take == ret){
            ans.push_back(i);
            getAnswer(i + 1, new_mask, people);
        }
        else{
            getAnswer(i + 1, mask, people);
        }
    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        // Hashing each string to an id.
        int id = 0;
        for(string skill: req_skills)
            mp[skill] = id++;
        
        n = reqw_skills.size();
        
        dp = vector<vector<int>> (people.size(), vector<int> (1 << n, -1));
        int min_cnt = go(0, 0, people);
        cout << min_cnt << endl;
        getAnswer(0, 0, people);
        
        return ans;
    }
};