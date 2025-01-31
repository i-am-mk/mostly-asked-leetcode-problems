// https://leetcode.com/problems/same-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr || q==nullptr)
            return p==q;   

        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

/*
 * Approach:
 * 1. If both trees are `nullptr`, they are the same.
 * 2. If only one of them is `nullptr`, they are not the same.
 * 3. If the values of the current nodes are different, return `false`.
 * 4. Recursively compare the left and right subtrees.

 * Time Complexity:
 * - O(N), where N is the number of nodes in the smaller tree.
 * - Each node is visited once.

 * Space Complexity:
 * - O(H), where H is the height of the tree.
 * - This accounts for the recursion stack depth (O(log N) for balanced trees, O(N) for skewed trees).
 */