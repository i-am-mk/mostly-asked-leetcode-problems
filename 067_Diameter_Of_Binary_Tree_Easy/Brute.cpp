// https://leetcode.com/problems/diameter-of-binary-tree/
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
    int longestDiameter = 0;
    int getHeight(TreeNode* root)
    {
        if(root==nullptr)
            return 0;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        return 1+max(left, right);
    }

    void getLongestDiameter(TreeNode* root)
    {
        if(root==nullptr)
            return;
        int left = getHeight(root->left);
        int right = getHeight(root->right);

        longestDiameter=max(longestDiameter, left+right);
        getLongestDiameter(root->left);
        getLongestDiameter(root->right);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        getLongestDiameter(root);
        return longestDiameter;
    }
};

/**
 * Approach:
 * 1. Use a helper function `getHeight` to calculate the height of the tree.
 *    - Calculate the height of left and right subtrees.
 *    - Return the height as `1 + max(left, right)`.
 * 2. Use another function `getLongestDiameter` to determine the longest diameter.
 *    - For each node, calculate the diameter as `left + right`.
 *    - Update `longestDiameter` if the current diameter is greater.
 *    - Recursively calculate the diameter for left and right subtrees.
 * 3. The `diameterOfBinaryTree` function initializes the process and returns the `longestDiameter`.
 * 
 * Time Complexity:
 * - O(N^2) in the worst case, where N is the number of nodes.
 * - Each call to `getLongestDiameter` calls `getHeight`, resulting in repeated calculations.
 * 
 * Space Complexity:
 * - O(H), where H is the height of the tree.
 * - In the worst case (skewed tree), recursion depth can be O(N).
 * - In the best case (balanced tree), recursion depth is O(log N).
 */