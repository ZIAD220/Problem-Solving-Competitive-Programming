const int N = 5e4 + 5;
int mem[N][2];

class Solution {
public:

    int n;

    int go(int idx, bool alice, vector<int> &stoneValue){
        if (idx == n)
            return 0;
        
        int &ret = mem[idx][alice];
        if (~ret)
            return ret;
        
        ret = (alice ? -1e9 : 1e9);
        int sum = 0;
        for(int i = idx; i < min(idx + 3, n); i++){
            sum += stoneValue[i];
            if (alice)
                ret = max(ret, go(i + 1, !alice, stoneValue) + sum);
            else
                ret = min(ret, go(i + 1, !alice, stoneValue));
        }
        return ret;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        memset(mem, -1, sizeof(mem));
        
        int sum = 0;
        for(int stone : stoneValue)
            sum += stone;
        
        int alice = go(0, true, stoneValue);
        int bob = sum - alice;

        return (alice == bob ? "Tie" : alice > bob ? "Alice" : "Bob");
    }
};