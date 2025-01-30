// https://leetcode.com/problems/task-scheduler/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> countOfOccurence(26, 0);
        for(auto ch: tasks)
            countOfOccurence[ch-'A']++;

        priority_queue<int> pq;
        for(int i=0; i<26; i++)
        {
            if(countOfOccurence[i]>0)
                pq.push(countOfOccurence[i]);
        }

        int ans = 0;
        while(!pq.empty())
        {
            vector<int> temp;
            for(int i=0; i<n+1; i++)
            {
                if(!pq.empty())
                {
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }
            for(auto freq: temp)
            {
                if(freq>0)
                    pq.push(freq);
            }
            if(pq.empty())
                ans+=temp.size();
            else
                ans+=n+1;
        }
        return ans;
    }
};