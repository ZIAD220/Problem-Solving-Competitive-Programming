class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<pair<int, int>> sortedPeople;
        int n = people.size();
        for(int i = 0; i < n; i++)
            sortedPeople.emplace_back(people[i], i);
        
        sort(sortedPeople.begin(), sortedPeople.end());

        vector<int> pre(n + 1);
        for(auto &flower: flowers){
            int start = flower[0];
            int end = flower[1];
            
            auto left = 
                lower_bound(sortedPeople.begin(), sortedPeople.end(), make_pair(start, -1));
            if (left == sortedPeople.end())
                continue;
            
            int leftIndex = left - sortedPeople.begin();

            auto right = 
                upper_bound(sortedPeople.begin(), sortedPeople.end(), make_pair(end + 1, -1));
            right--;

            int rightIndex = right - sortedPeople.begin();

            pre[leftIndex]++;
            pre[rightIndex + 1]--;
        }

        for(int i = 1; i < n; i++)
            pre[i] += pre[i - 1];

        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            int index = sortedPeople[i].second;
            ans[index] = pre[i];
        }
        
        return ans;
    }
};