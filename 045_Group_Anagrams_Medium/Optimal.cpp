// https://leetcode.com/problems/group-anagrams/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> groupAnagramByKey;
        for(auto it: strs)  
        {
            string key = it;
            sort(key.begin(), key.end());
            groupAnagramByKey[key].push_back(it);
        }

        vector<vector<string>> ans;
        for(auto it: groupAnagramByKey)
            ans.push_back(it.second);
        return ans;
    }
};