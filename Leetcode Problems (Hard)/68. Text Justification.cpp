class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();

        int i = 0;
        while(i < n)
        {
            vector<string> line = {words[i++]};
            int curWidth = line[0].length();
            while(i < n && curWidth + words[i].length() + 1 <= maxWidth)
            {
                line.push_back(" " + words[i]);
                curWidth += words[i++].length() + 1;
            }

            // If this is just one word or this is the last line. make it left-justified.
            if ((int)line.size() == 1 || i == n){
                while(curWidth < maxWidth)
                {
                    line.back() += ' ';
                    curWidth++;
                }
            }
            else{
                // Adding extra spaces evenly.
                int sz = line.size();
                for(int j = 0; j < sz - 1 && curWidth < maxWidth; j = (j + 1) % (sz - 1))
                {
                    line[j] += ' ';
                    curWidth++;
                }
            }


            ans.push_back("");
            for(string s : line)
                ans.back() += s;
        }
        return ans;
    }
};