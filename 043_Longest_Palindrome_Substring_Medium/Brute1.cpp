// https://leetcode.com/problems/longest-palindromic-substring/ TLE
class Solution {
public:
    bool isPalindrome(string s)
    {
        int left = 0;
        int right = s.length()-1;
        while(left<=right)
        {
            if(s[left]!=s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        if(n==1)
            return s;
        string longPal = s.substr(0,1);
        int maxLen = 1;
        for(int i=0; i<n; i++)
        {
            for(int j=i+maxLen; j<=n; j++)
            {
                if(j-i>maxLen && isPalindrome(s.substr(i, j-i)))
                {
                    maxLen=j-i;
                    longPal=s.substr(i, j-i);
                }
            }
        }
        return longPal;
    }
};