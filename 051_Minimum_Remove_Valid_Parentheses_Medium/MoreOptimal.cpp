// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        string temp="";
        int countOfOpen = 0;
        int diff=0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='(')
            {
                diff++;
                countOfOpen++;
                temp.push_back(s[i]);
            }
            else if(s[i]==')')
            {
                if(diff==0)
                    continue;
                diff--;
                temp.push_back(s[i]);
            }
            else
                temp.push_back(s[i]);
        }
        string ans = "";
        int valid = countOfOpen - diff;
        for(int i=0; i<temp.length(); i++)
        {
            if(temp[i]=='(')
            {
                valid--;
                if(valid<0)
                    continue;
            }
            ans.push_back(temp[i]);
        }
        return ans;
    }
};