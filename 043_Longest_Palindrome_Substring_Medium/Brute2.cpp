// https://leetcode.com/problems/longest-palindromic-substring/ MLE
class Solution {
public:
    int dp[1001][1001];
    bool solve(string s, int l, int r)
    {
        if(l>=r)
            return true;
        if(dp[l][r]!=-1)
            return dp[l][r];
        if(s[l]==s[r])
            return solve(s, l+1, r-1);
        return dp[l][r]=false;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        if(n==1)
            return s;
        int maxLen = INT_MIN;
        int startIndex = 0;
        memset(dp,-1, sizeof(dp));
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                if(solve(s,i,j))
                {
                    if(j-i+1>maxLen)
                    {
                        maxLen=j-i+1;
                        startIndex=i;
                    }
                }
            }
        }
        return s.substr(startIndex, maxLen);
    }
};