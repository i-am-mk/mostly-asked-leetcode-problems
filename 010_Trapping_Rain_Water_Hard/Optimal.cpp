// https://leetcode.com/problems/trapping-rain-water/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        int leftMax = 0;
        int rightMax = 0;
        for(int i=0; i<n; i++)
        {
            leftMax=max(leftMax, height[i]);
            left[i]=leftMax;
        }
        for(int j=n-1; j>=0; j--)
        {
            rightMax=max(rightMax, height[j]);
            right[j]=rightMax;
        }

        int trapWater = 0;
        int i = 0;
        while(i<n)
        {
            trapWater += min(left[i], right[i]) - height[i];
            i++;
        }
        return trapWater;
    }
};