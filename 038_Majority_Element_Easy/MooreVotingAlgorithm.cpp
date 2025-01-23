// https://leetcode.com/problems/majority-element/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ele;
        int count = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(count==0)
            {
                count++;
                ele=nums[i];
            }
            else
            {
                if(nums[i]==ele)
                    count++;
                else
                    count--;
            }
        }
        return ele;
    }
};