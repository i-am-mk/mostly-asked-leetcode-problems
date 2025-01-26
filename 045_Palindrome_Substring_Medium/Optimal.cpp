// https://leetcode.com/problems/palindromic-substrings/ MLE
class Solution {
public:
    bool isPalindrome(string s, int left, int right, vector<vector<int>> &dp)
    {
        if(left>=right)
            return 1;
        if(dp[left][right]!=-1)
            return dp[left][right];
        return dp[left][right] = s[left]==s[right] ? isPalindrome(s, left+1, right-1, dp) : 0;
    }

    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp = vector<vector<int>> (s.size(), vector<int>(s.size(), -1));
        int count = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
                count+=isPalindrome(s, i, j, dp);
        }
        return count;
    }
};