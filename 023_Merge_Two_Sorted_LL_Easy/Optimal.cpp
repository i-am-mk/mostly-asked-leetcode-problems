// https://leetcode.com/problems/merge-two-sorted-lists/
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> vc;
        ListNode* dummy = new ListNode(-1);        
        ListNode* current = dummy;
        while(list1!=nullptr && list2!=nullptr)
        {
            if(list1->val<list2->val)
            {
                current->next = new ListNode(list1->val);
                current = current->next;
                list1=list1->next;
            }
            else
            {
                current->next = new ListNode(list2->val);
                current = current->next;
                list2=list2->next;
            }
        }

        while(list1!=nullptr)
        {
            current->next = new ListNode(list1->val);
            current = current->next;
            list1=list1->next;
        }
        while(list2!=nullptr)
        {
            current->next = new ListNode(list2->val);
            current = current->next;
            list2=list2->next;
        }
        return dummy->next;
    }
};