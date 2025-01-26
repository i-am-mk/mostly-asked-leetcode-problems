// https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char> st;
        int maxCount = 0;
        int left = 0;
        int right = 0;
        while(right<n)
        {
            if(st.find(s[right])==st.end())
            {
                st.insert(s[right]);
                maxCount = max(maxCount, right-left+1);
                right++;
            }
            else
            {
                st.erase(s[left]);
                left++;
            }
        }
        return maxCount;
    }
};