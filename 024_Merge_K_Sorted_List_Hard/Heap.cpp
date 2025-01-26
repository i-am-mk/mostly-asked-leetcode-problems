// https://leetcode.com/problems/merge-k-sorted-lists/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Node {
    public:
        int val;
        int row;
        ListNode* node;
    Node(int val, int row, ListNode* node)
    {
        this->val = val;
        this->row = row;
        this->node = node;
    }
};

class Compare {
    public: 
        bool operator()(Node* a, Node* b)
        {
            return a->val > b->val;
        }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<Node*, vector<Node*>, Compare> pq;
        for(int i=0; i<lists.size(); i++)       
        {
            if(lists[i]!=nullptr)
                pq.push(new Node(lists[i]->val, i, lists[i]));
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;

        while(!pq.empty())
        {
            Node* temp = pq.top();
            pq.pop();
            int row = temp->row;
            current->next = new ListNode(temp->val);
            current=current->next;
            if (temp->node->next != nullptr) {
                pq.push(new Node(temp->node->next->val, temp->row, temp->node->next));
            }
        }

        return dummy->next;
    }
};