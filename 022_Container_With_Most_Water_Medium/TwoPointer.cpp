// https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int maxWater = INT_MIN;
        while(left<right)
        {
            int w = right - left;
            int h = min(height[left], height[right]);
            maxWater = max(maxWater, w*h);
            if(height[left]<height[right])
                left++;
            else
                right--;
        }

        return maxWater;
    }
};