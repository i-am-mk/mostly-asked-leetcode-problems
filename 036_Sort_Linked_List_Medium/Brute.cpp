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
    ListNode* sortList(ListNode* head) {
        ListNode* temp = head;
        vector<int> nums;
        while(temp!=nullptr)
        {
            nums.push_back(temp->val);
            temp = temp -> next;
        }
        sort(nums.begin(), nums.end());
        temp = head;
        int i = 0;
        while(temp!=nullptr)
        {
            temp->val = nums[i++];
            temp=temp->next;
        }
        return head;
    }
};