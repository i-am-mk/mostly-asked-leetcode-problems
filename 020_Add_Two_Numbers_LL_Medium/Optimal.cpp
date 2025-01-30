// https://leetcode.com/problems/add-two-numbers/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        while(temp1!=nullptr || temp2!=nullptr || carry)
        {
            int sum = carry;
            if(temp1!=nullptr)
            {
                sum += temp1->val;
                temp1=temp1->next;
            }
            if(temp2!=nullptr)
            {
                sum += temp2->val;
                temp2=temp2->next;
            }
            current->next = new ListNode(sum % 10);
            current = current->next;
            carry = sum/10;
        }
        return dummy->next;
    }
};

// Approach:
// 1. Use two pointers (`temp1` and `temp2`) to traverse the given linked lists.
// 2. Maintain a `carry` variable to store any overflow from the sum of two digits.
// 3. Initialize a dummy node and a `current` pointer to construct the result linked list.
// 4. Loop through both lists until all digits are processed:
//    - Add the values from both lists and the carry.
//    - Create a new node with the last digit of the sum (`sum % 10`).
//    - Move the `current` pointer to this new node.
//    - Update the carry (`sum / 10`) for the next iteration.
// 5. If a carry remains after processing both lists, create a new node for it.
// 6. Return `dummy->next`, skipping the dummy node to get the final result.
 
// Complexity Analysis
// Time Complexity: O(max(N, M)), where N and M are the lengths of the input linked lists.
// - Each node is processed once, making the complexity linear.
// Space Complexity: O(max(N, M)), since we create a new linked list to store the result.