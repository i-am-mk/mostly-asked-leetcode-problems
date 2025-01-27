// https://leetcode.com/problems/largest-rectangle-in-histogram/
class Solution {
public:
    vector<int> nextSmallerElement(vector<int> heights)
    {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && heights[i]<=heights[st.top()])
                st.pop();
            if(st.empty())
                ans[i]=n;
            else
                ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int> heights)
    {
        int n = heights.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=0; i<n; i++)
        {
            while(!st.empty() && heights[i]<=heights[st.top()])
                st.pop();
            if(st.empty())
                ans[i]=-1;
            else
                ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse = prevSmallerElement(heights);
        vector<int> nse = nextSmallerElement(heights);
        int ans=INT_MIN;
        for(int i=0; i<n; i++)
            ans=max(ans, heights[i]*(nse[i]-pse[i]-1));
        return ans;
    }
};