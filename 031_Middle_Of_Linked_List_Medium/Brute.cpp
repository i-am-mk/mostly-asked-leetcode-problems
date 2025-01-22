// https://leetcode.com/problems/middle-of-the-linked-list/
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
    ListNode* middleNode(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode* temp = head;
        int count = 0;
        while(temp!=nullptr)
        {
            count++;
            temp = temp->next;
        }
        int middle = (count/2);
        temp = head;
        while(temp!=nullptr)
        {
            --middle;
            if(middle==0)
                break;
            temp = temp->next;
        }
        return temp->next;
    }
};