// https://leetcode.com/problems/maximum-depth-of-binary-tree/
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
    int getHeight(TreeNode* root)
    {
        if(root==nullptr)
            return 0;
        int left = getHeight(root->left, 0);
        int right = getHeight(root->right, 0);

        return 1+max(left, right);
    }

public:
    int maxDepth(TreeNode* root) {
        return getHeight(root);
    }
};

/**
 * Approach:
 * 1. If the root is `nullptr`, return `0` as the base case.
 * 2. Recursively compute the depth of the left and right subtrees.
 * 3. Return `1 + max(leftDepth, rightDepth)` to get the maximum depth.
 * 
 * Time Complexity:
 * - O(N), where N is the number of nodes in the tree.
 * - Each node is visited once, leading to linear time complexity.
 * 
 * Space Complexity:
 * - O(H), where H is the height of the tree.
 * - In the worst case (skewed tree), recursion depth can be O(N).
 * - In the best case (balanced tree), recursion depth is O(log N).
 */
