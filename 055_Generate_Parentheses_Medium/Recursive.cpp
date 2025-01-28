// https://leetcode.com/problems/generate-parentheses/
class Solution {
private:
    void helperFunctionToGenerateParentheses(vector<string> &ans, string curr, int open, int close, int n)
    {
        if(curr.length()==2*n)
        {
            ans.push_back(curr);
            return;
        }
        
        if(open<n)
            helperFunctionToGenerateParentheses(ans, curr+"(", open+1, close, n);
        if(close<open)
            helperFunctionToGenerateParentheses(ans, curr+")", open, close+1, n);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helperFunctionToGenerateParentheses(ans, "", 0, 0, n);
        return ans;
    }
};