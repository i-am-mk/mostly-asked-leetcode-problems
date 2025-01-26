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
    bool isPalindrome(ListNode* head) {
        vector<int> vc;
        ListNode* temp = head;
        while(temp!=nullptr)
        {
            vc.push_back(temp->val);
            temp=temp->next;
        }
        int start = 0;
        int end = vc.size()-1;
        while(start<end)
        {
            if(vc[start]!=vc[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
};