// https://leetcode.com/problems/reorder-list/
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
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<int> vc;
        ListNode* temp = head;
        while(temp!=nullptr)
        {
            vc.push_back(temp->val);
            temp = temp->next;
        }
    
        int start = 0;
        int end = vc.size() - 1;
        bool startPriority = true;
        bool endPriority = false;
        temp = head;
        while(start<=end)
        {
            if(startPriority)
            {
                temp->val = vc[start];
                startPriority = false;
                endPriority = true;
                start++;
            }
            else
            {
                temp->val = vc[end];
                endPriority = false;
                startPriority = true;
                end--;
            }
            temp = temp -> next;
        }
    }
};