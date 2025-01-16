// https://leetcode.com/problems/3sum/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> unique;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                for(int k=j+1; k<n; k++)
                {
                    int sum = nums[i]+nums[j]+nums[k];
                    if(sum==0)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        unique.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> ans(unique.begin(), unique.end());
        return ans;
    }
};