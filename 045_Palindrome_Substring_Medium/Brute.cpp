// https://leetcode.com/problems/palindromic-substrings/
class Solution {
public:
    bool isPalindrome(string s, int left, int right)
    {
        if(left>=right)
            return 1;
        return s[left]==s[right] ? isPalindrome(s, left+1, right-1) : 0;
    }

    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
                count+=isPalindrome(s, i, j);
        }
        return count;
    }
};