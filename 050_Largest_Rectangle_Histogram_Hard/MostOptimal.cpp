// https://leetcode.com/problems/largest-rectangle-in-histogram/
class Solution {
public:
    int getAns(vector<int> heights, int n)
    {
        stack<int> st;
        int ans=INT_MIN;
        for(int i=0; i<n; i++)
        {
            while(!st.empty() && heights[i]<=heights[st.top()])
            {
                int index = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                ans=max(ans, heights[index]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty())
        {
            int index = st.top();
            st.pop();
            int nse = n;
            int pse = st.empty() ? -1 : st.top();
            ans=max(ans, heights[index]*(nse-pse-1));
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = getAns(heights, n);
        return ans;
    }
};