// https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution {
public:
    int getPivot(vector<int>& nums, int low, int high)
    {
        if(low>=high)
            return low;
        int mid = (low+high)/2;
        if(nums[mid]>=nums[0])
            return getPivot(nums, mid+1, high);
        else
            return getPivot(nums, low, mid);
    }

    int binarySearch(vector<int>& nums, int low, int high, int target)
    {
        if(low>high)
            return -1;
        int mid = (low+high)/2;
        if(nums[mid]==target)
            return mid;
        else if(nums[mid]>target)
            return binarySearch(nums, low, mid-1, target);
        else
            return binarySearch(nums, mid+1, high, target);
    }

    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int pivot = getPivot(nums, low, high);
        if(nums[pivot]<=target && nums[high]>=target)
            return binarySearch(nums, pivot, high, target);
        else
            return binarySearch(nums, low, pivot-1, target);
    }
};