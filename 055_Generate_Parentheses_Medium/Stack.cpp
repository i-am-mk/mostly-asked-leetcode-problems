// https://leetcode.com/problems/generate-parentheses/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        stack<string> temp; 
        temp.push("");
        vector<string> ans;
        while(!temp.empty())
        {
            string curr = temp.top();
            temp.pop();

            if(curr.length()==2*n)
            {
                ans.push_back(curr);
                continue;
            }

            int open = count(curr.begin(), curr.end(), '(');
            int close = curr.length() - open;

            if(open<n)
                temp.push(curr+"(");
            if(close<open)
                temp.push(curr+")");
        }
        return ans;
    }
};