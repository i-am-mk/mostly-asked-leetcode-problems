// https://leetcode.com/problems/median-of-two-sorted-arrays/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0;
        int j = 0;
        while(i<n1 && j<n2)
        {
            if(nums1[i]<nums2[j])
            {
                nums3.push_back(nums1[i]);
                i++;
            }
            else
            {
                nums3.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n1)
        {
            nums3.push_back(nums1[i]);
            i++;
        }
        while(j<n2)
        {
            nums3.push_back(nums2[j]);
            j++;
        }
        int n3 = nums3.size();
        if(n3%2==1)
            return nums3[n3/2];
        else
            return (double)((double)nums3[n3/2]+(double)nums3[(n3/2)-1])/2.0;
    }
};