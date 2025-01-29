// https://leetcode.com/problems/last-stone-weight/
class Solution {
private:
    priority_queue<int>pq;
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        for(int i=0; i<n; i++)
            pq.push(stones[i]);
        while(pq.size()!=1)
        {
            int num1 = pq.top();
            pq.pop();
            int num2 = pq.top();
            pq.pop();
            if(num1!=num2)
                pq.push(abs(num1-num2));
        }
        return pq.empty() ? 0 : pq.top(); 
    }
};