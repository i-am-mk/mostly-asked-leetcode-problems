// https://leetcode.com/problems/k-closest-points-to-origin/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<int>> ans;
        for(int i=0; i<n; i++)
        {
            pair<int, pair<int, int>> temp = {points[i][0]*points[i][0] + points[i][1] * points[i][1], {points[i][0], points[i][1]}}; 
            pq.push(temp);
            if(pq.size()>k)
                pq.pop();
        }
        while(!pq.empty())
        {
            pair<int, int> temp = pq.top().second;
            ans.push_back({temp.first, temp.second});
            pq.pop();
        }
        return ans;
    }
};