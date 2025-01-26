// https://leetcode.com/problems/3sum/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> unique;
        for(int i=0; i<n; i++)
        {
            set<int> prev;
            for(int j=i+1; j<n; j++)
            {
                int third = -(nums[i]+nums[j]);
                if(prev.find(third)!=prev.end())
                {
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    unique.insert(temp);
                }
                prev.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(unique.begin(), unique.end());
        return ans;
    }
};