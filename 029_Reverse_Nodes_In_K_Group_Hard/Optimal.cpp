// https://leetcode.com/problems/reverse-nodes-in-k-group/
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
    ListNode* getKNode(ListNode* head, int k)
    {
        ListNode* temp = head;
        while(temp!=nullptr)
        {
            --k;
            if(k==0)
                return temp;
            temp = temp -> next;
        }
        return temp;
    }

    void reversed(ListNode* head)
    {
        ListNode* temp = head;
        ListNode* prevNode = nullptr;
        while(temp!=nullptr)
        {
            ListNode* front = temp -> next;
            temp -> next = prevNode;
            prevNode = temp;
            temp = front;
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
      ListNode* temp = head;
      ListNode* prevNode = nullptr;
      ListNode* nextNode = nullptr;
      while(temp!=nullptr)
      {
        ListNode* kNode = getKNode(temp, k);
        if(kNode!=nullptr)
        {
            ListNode* nextNode = kNode->next;
            kNode->next = nullptr;
            reversed(temp);
            if(head==temp)
                head = kNode;
            else
                prevNode->next = kNode;
            temp->next = nextNode;
            prevNode = temp;
            temp = nextNode;
        }
        else
        {
            if(prevNode!=nullptr)
                prevNode->next = temp;
            break;
        }
      }
    
    return head;
    }
};