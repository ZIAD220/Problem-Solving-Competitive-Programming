class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> count(26);
        for(char c: letters)
            count[c - 'a']++;
        
        int size = words.size();
        int maxScore = 0;
        for(int mask = 0; mask < (1 << size); mask++) {
            int curScore = 0;
            vector<int> curCount(26);
            bool possible = true;
            for(int i = 0; i < size; i++) {
                if (!(mask & (1 << i)))
                    continue;
                
                for(char c: words[i]) {
                    curCount[c - 'a']++;
                    if (curCount[c - 'a'] > count[c - 'a']) {
                        possible = false;
                        break;
                    }
                    if (!possible)
                        break;
                    curScore += score[c - 'a'];
                }
            }
            if (possible) {
                maxScore = max(maxScore, curScore);
            }
        }
        return maxScore;
    }
};