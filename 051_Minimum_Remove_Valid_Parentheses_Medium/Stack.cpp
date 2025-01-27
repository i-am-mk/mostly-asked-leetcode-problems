// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<int> st;
        unordered_set<int> badIndexes;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(')
                st.push(i);   
            else if(s[i]==')')
            {
                if(st.empty())
                    badIndexes.insert(i);
                else
                    st.pop();
            }
        }
        while(!st.empty())
        {
            badIndexes.insert(st.top());
            st.pop();
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