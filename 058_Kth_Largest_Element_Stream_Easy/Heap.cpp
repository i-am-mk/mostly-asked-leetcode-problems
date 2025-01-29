// https://leetcode.com/problems/kth-largest-element-in-a-stream/
class KthLargest {
private:
    int kthIndex;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        kthIndex = k;
        for(auto num: nums)
        {
            pq.push(num);
            if(pq.size()>kthIndex)
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>kthIndex)
            pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */