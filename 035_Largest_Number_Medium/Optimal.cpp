// https://leetcode.com/problems/largest-number/
class Solution {
public:
    static bool compare(const string &a, const string &b) {
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> vc;
        for(int i=0; i<nums.size(); i++)
            vc.push_back(to_string(nums[i]));
        sort(vc.begin(), vc.end(), compare);
        if(vc[0]=="0")
            return "0";
        string ans;
        for(auto st : vc)
            ans+=st;
        return ans;
    }
};