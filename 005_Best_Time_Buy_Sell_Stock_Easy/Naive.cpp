// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxi = 0;
        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
                maxi=max(prices[j]-prices[i], maxi);
        }
        return maxi;
    }
};