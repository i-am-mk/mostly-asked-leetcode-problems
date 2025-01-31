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
    int height(TreeNode* root)
    {
        if(root==nullptr)
            return 0;
        return 1+max(height(root->left),height(root->right));
    }

    bool check(TreeNode* root)
    {
        if(root==nullptr)
            return true;
        int left = height(root->left);
        int right = height(root->right);
        if(abs(right-left)>1)
            return false;
        return check(root->left) && check(root->right);
    }

public:
    bool isBalanced(TreeNode* root) {
        return check(root);
    }
};

/*
 * Approach:
 * 1. Use a helper function `height` to compute the height of a subtree recursively.
 * 2. Define a function `check` that:
 *    - Calculates the height of the left and right subtrees.
 *    - Checks if the absolute difference in height is greater than 1 (if so, return false).
 *    - Recursively checks for balance in left and right subtrees.
 * 3. The tree is balanced if all nodes satisfy this condition.

 * Time Complexity:
 * - O(N^2) in the worst case.
 * - The `height` function is called for every node, leading to repeated computations.

 * Space Complexity:
 * - O(H), where H is the height of the tree (O(log N) for balanced trees, O(N) for skewed trees).
 * - This accounts for the recursion stack depth.
*/