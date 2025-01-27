// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        int diff=0;
        unordered_set<int> badIndexes;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(')
                diff++;   
            else if(s[i]==')')
            {
                if(diff==0)
                    badIndexes.insert(i);
                else
                    diff--;
            }
        }
        for(int i=n-1; i>=0 && diff>0; i--)
        {
            if(s[i]=='(')
            {
                diff--;
                badIndexes.insert(i);
            }
        }
        string ans="";
        for(int i=0; i<n; i++)
        {
            if(!badIndexes.contains(i))
                ans.push_back(s[i]);    // Alway try to do it by ans.push_back if we try ans+= (Takes 0(n) to insert)
        }
        return ans;
    }
};