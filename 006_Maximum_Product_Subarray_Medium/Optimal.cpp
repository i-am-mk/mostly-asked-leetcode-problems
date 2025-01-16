// https://leetcode.com/problems/maximum-product-subarray/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int minProd = nums[0];
        int maxProd = nums[0];
        int result = nums[0];
        for(int i=1; i<n; i++)
        {
            if(nums[i]<0)
                swap(minProd, maxProd);
            minProd = min(nums[i], minProd*nums[i]);
            maxProd = max(nums[i], maxProd*nums[i]);
            result = max(maxProd, result);
        }
        return result;
    }
};