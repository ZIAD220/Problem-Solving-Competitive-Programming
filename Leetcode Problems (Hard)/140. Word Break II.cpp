class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> wordMap;
        for(string &word: wordDict)
            wordMap[word] = true;

        vector<string> sentences;        
        for(int mask = 0; mask < 1 << s.length(); mask++) {
            string sentence;
            int spaceIndex = -1;
            bool possible = true;
            for(int i = 0; i < s.length(); i++) {
                if (!(mask & (1 << i)))
                    continue;
                
                string word;
                for(int j = spaceIndex + 1; j <= i; j++)
                    word.push_back(s[j]);
                
                if (spaceIndex != -1)
                    sentence += " ";
                sentence += word;
                
                if (wordMap.count(word) == 0) {
                    possible = false;
                    break;
                }

                spaceIndex = i;
            }
            string word;
            for(int j = spaceIndex + 1; j < s.length(); j++)
                word.push_back(s[j]);
            if (spaceIndex != -1)
                sentence += " ";
            sentence += word;
                
            if (wordMap.count(word) == 0) {
                possible = false;
            }

            if (possible)
                sentences.push_back(sentence);
        }
        return sentences;
    }
};