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
        if(!head || !head->next || !head->next->next)
            return;
        
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=nullptr && fast->next->next!=nullptr)
        {
            slow = slow -> next;
            fast = fast ->next -> next;
        }

        ListNode* l1 = head;
        ListNode* l2 = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        while(l2!=nullptr)
        {
            ListNode* front = l2->next;
            l2->next = prev;
            prev = l2;
            l2 = front;
        }
        ListNode* first = head;
        ListNode* second = prev;
        while(second!=nullptr)
        {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};