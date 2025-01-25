// https://leetcode.com/problems/valid-parentheses/
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        string temp;
        map<char,char> mp;
        mp['(']=')';
        mp['{']='}';
        mp['[']=']';
        for(int i=0; i<n; i++)
        {
            if(mp.count(s[i]))
                temp.push_back(s[i]);
            else
            {
                if(temp.empty() || mp[temp.back()] != s[i])
                    return false;
                temp.pop_back();
            }
        }
        return temp.empty();
    }
};