// https://leetcode.com/problems/balanced-binary-tree/
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
private:
    int check(TreeNode* root)
    {
        if(root==nullptr)
            return 0;
        int left = check(root->left);
        if(left==-1)
            return -1;
        int right = check(root->right);
        if(right==-1)
            return -1;
        if(abs(right-left)>1)
            return -1;
        return 1+max(left, right);
    }

public:
    bool isBalanced(TreeNode* root) {
        return check(root)!=-1;
    }
};

/*
 * Approach:
 * 1. Use a helper function `check` that returns the height of the subtree if it is balanced.
 * 2. If the left or right subtree is unbalanced (`-1`), return `-1` immediately.
 * 3. Calculate the height difference between left and right subtrees.
 * 4. If the difference is greater than 1, return `-1` (indicating imbalance).
 * 5. Otherwise, return the height of the current node (1 + max(left, right)).

 * Time Complexity:
 * - O(N), where N is the number of nodes in the tree.
 * - Each node is visited once, and its height is computed in a **single traversal**.

 * Space Complexity:
 * - O(H), where H is the height of the tree.
 * - This accounts for the recursion stack depth (O(log N) for balanced trees, O(N) for skewed trees).

 * This is an optimized approach compared to the previous O(N²) solution.
 */