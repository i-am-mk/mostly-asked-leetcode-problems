// https://leetcode.com/problems/minimum-window-substring/
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(!n || !m)
            return "";
        
        int hash[256] = {0};
        for(int i=0; i<m; i++)
            hash[t[i]]++;

        int startIndex = 0;
        int minLength = INT_MAX;
        int left = 0;
        int right = 0;
        int count = 0;
        
        while(right<n)
        {
            hash[s[right]]--;
            if(hash[s[right]]>=0)
                count++;
            while(left<=right && count==m)
            {
                if(right-left+1 < minLength)
                {
                    minLength = right-left+1;
                    startIndex = left;
                }
                hash[s[left]]++;
                if(hash[s[left]]>0)
                    --count;
                left++;
            }
            right++;
        }

        return minLength != INT_MAX ? s.substr(startIndex, minLength) : "";
    }
};