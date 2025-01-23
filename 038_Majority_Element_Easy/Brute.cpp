// https://leetcode.com/problems/majority-element/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majNum = -1;
        for(int i=0; i<n; i++)
        {
            int count = 0;
            for(int j=0; j<n; j++)
            {
                if(nums[i]==nums[j])
                    count++;
                if(count>n/2)
                {
                    majNum = nums[i];
                    break;
                }
            }
        }
        return majNum;
    }
};