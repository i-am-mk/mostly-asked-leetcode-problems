class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        int mapping[256] = {0};
        for(auto it: s)
            mapping[it-'a']++;
        for(auto it: t)
            mapping[it-'a']--;
        for(auto it: mapping)
        {
            if(it!=0)
                return false;
        }
        return true;
    }
};