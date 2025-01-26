// https://leetcode.com/problems/palindromic-substrings/
class Solution {
public:
    int checkPalindrome(string s, int n, int left, int right)
    {
        int count = 0;
        while(left>=0 && right<n && s[left]==s[right])
        {
            count++;
            left--;
            right++;
        }
        return count;
    }

    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        for(int i=0; i<n; i++)
        {
            count+=checkPalindrome(s, n, i, i);
            count+=checkPalindrome(s, n, i, i+1);
        }
        return count;
    }
};