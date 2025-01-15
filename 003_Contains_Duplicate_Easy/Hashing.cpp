// https://leetcode.com/problems/contains-duplicate/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++)
        {
            if(mp[nums[i]]>0)
                return true;
            mp[nums[i]]++;
        }
        return false;
    }
};