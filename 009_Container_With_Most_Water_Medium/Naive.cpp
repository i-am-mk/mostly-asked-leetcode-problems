// https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxWater = INT_MIN;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int w = j - i;
                int h = min(height[i], height[j]);
                maxWater=max(maxWater, w*h);
            }
        }
        return maxWater;
    }
};