// https://leetcode.com/problems/palindrome-linked-list/
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
    ListNode* reverse(ListNode* head)
    {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(temp!=nullptr)
        {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=nullptr && fast->next->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* secondHalf = reverse(slow->next);
        ListNode* firstHalf = head;
        ListNode* secondHalfCopy = secondHalf;
        while(secondHalf!=nullptr)
        {
            if(secondHalf->val!=firstHalf->val)
            {
                reverse(secondHalfCopy);
                return false;
            }
            firstHalf=firstHalf->next;
            secondHalf=secondHalf->next;
        }
        reverse(secondHalfCopy);
        return true;
    }
};