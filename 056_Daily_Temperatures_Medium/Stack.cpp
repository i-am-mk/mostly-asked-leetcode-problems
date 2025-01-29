// https://leetcode.com/problems/daily-temperatures/
class Solution {
vector<int> nge(vector<int> temperatures)
{
    int n = temperatures.size();
    vector<int> ans(n, 0);
    stack<int> st;
    for(int i=n-1; i>=0; i--)
    {
        while(!st.empty() && temperatures[i] >= temperatures[st.top()])
        {
            st.pop();
        }
        ans[i]=st.empty() ? 0 : st.top() - i;
        st.push(i);
    }
    return ans;
}

public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans = nge(temperatures);
        return ans;
    }
};