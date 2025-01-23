// https://leetcode.com/problems/majority-element/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majNum = -1;
        map<int, int> mp;
        for(int i=0; i<n; i++)
            mp[nums[i]]++;
        for(auto it: mp)
        {
            if(it.second>(n/2))
            {
                majNum = it.first;
                break;
            }
        }
        return majNum;
    }
};