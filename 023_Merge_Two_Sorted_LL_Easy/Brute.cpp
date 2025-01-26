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
        while(list1!=nullptr && list2!=nullptr)
        {
            if(list1->val<list2->val)
            {
                vc.push_back(list1->val);
                list1=list1->next;
            }
            else
            {
                vc.push_back(list2->val);
                list2=list2->next;
            }
        }

        while(list1!=nullptr)
        {
            vc.push_back(list1->val);
            list1=list1->next;
        }
        while(list2!=nullptr)
        {
            vc.push_back(list2->val);
            list2=list2->next;
        }
        ListNode* dummy = new ListNode(-1);        
        ListNode* current = dummy;
        for(int i=0; i<vc.size(); i++)
        {
            current->next = new ListNode(vc[i]);
            current = current->next;
        }
        return dummy->next;
    }
};