// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int count = 0;
        while(temp!=nullptr)
        {
            count++;
            temp=temp->next;
        }
        if(count==n)
            return head->next;
        else
        {
            count = count - n;
            temp = head;
            while(temp!=nullptr)
            {
                --count;
                if(count==0)
                    break;
                temp = temp->next;
            }
            ListNode* deleteNode = temp->next;
            temp->next = temp->next-> next;
            delete deleteNode;
            return head;
        }
    }
};