// https://leetcode.com/problems/sort-list/
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
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while(l1!=nullptr && l2!=nullptr)
        {
            if(l1->val<l2->val)
            {
                curr->next = l1;
                l1=l1->next;
            }
            else
            {
                curr->next = l2;
                l2=l2->next;
            }
            curr = curr->next;
        }
        if(l1!=nullptr)
            curr->next=l1;
        if(l2!=nullptr)
            curr->next=l2;

        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }  
        fast = slow->next;
        slow->next = nullptr;
        return merge(sortList(head), sortList(fast));
    }
};