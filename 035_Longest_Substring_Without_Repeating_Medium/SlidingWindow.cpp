// https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector<int> lastSeenIndex(128, -1);
        int maxi = 0;
        int winStart = 0;
        for(int winEnd=0; winEnd<n; winEnd++)
        {
            if(lastSeenIndex[s[winEnd]] >= winStart)
                winStart = lastSeenIndex[s[winEnd]]+1;
            lastSeenIndex[s[winEnd]] = winEnd;
            maxi = max(maxi, winEnd-winStart+1);
        }
        return maxi;
    }
};