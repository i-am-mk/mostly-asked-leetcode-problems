// https://leetcode.com/problems/invert-binary-tree/
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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr)
            return nullptr;
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;

        return root;
    }
};

// Approach
// 1. If the root is `nullptr`, return `nullptr` (base case).
// 2. Recursively call `invertTree()` on the left and right subtrees.
// 3. Swap the left and right children after recursive calls return.
// 4. Return the root node after swapping.

// Time Complexity
// - O(N), where N is the number of nodes in the tree.
// - Each node is visited once, leading to a linear time complexity. 
// Space Complexity
// - O(H), where H is the height of the tree.
// - In the worst case (skewed tree), recursion depth can be O(N).
// - In the best case (balanced tree), recursion depth is O(log N).