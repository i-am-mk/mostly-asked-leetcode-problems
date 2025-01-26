// https://leetcode.com/problems/text-justification/
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> ans;
        int index = 0;
        while(index<n)
        {
            int totalChars = words[index].size();
            int last = index+1;
            while(last<n && totalChars+words[last].size()+(last-index)<=maxWidth)
            {
                totalChars+=words[last].size();
                last++;
            }
            string line="";
            int wordSpaces = maxWidth - totalChars;
            if(last==n || last-index==1)
            {
                for(int i=index; i<last; i++)
                {
                    line+=words[i];
                    if (i < last - 1) line += " "; 
                }
                line += string(maxWidth - line.size(), ' ');
            }
            else
            {
                int extraSpaces = wordSpaces%(last-index-1);
                int perSpaces = wordSpaces/(last-index-1);
                for(int i=index; i<last; i++)
                {
                    line+=words[i];
                    if(i<last-1)
                    {
                        line+=string(perSpaces + (extraSpaces > 0 ? 1 : 0), ' ');
                        if(extraSpaces>0)
                            extraSpaces--;
                    }
                }
            }
            ans.push_back(line);
            index=last;
        }
        return ans;
    }
};