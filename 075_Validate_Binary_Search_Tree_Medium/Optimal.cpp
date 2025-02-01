// https://leetcode.com/problems/validate-binary-search-tree/
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
    bool isValid(TreeNode* root, pair<long, long> range)
    {
        if(root==nullptr)
            return true;
        if(!(root->val>range.first && root->val<range.second))
            return false;
        return isValid(root->left, {range.first, root->val}) && isValid(root->right, {root->val, range.second});
    }

public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, {LONG_MIN, LONG_MAX});
    }
};

/*
 * Approach:
 * 1. We need to check if all nodes in the tree satisfy the BST properties.
 * 2. The root's left subtree should have values less than the root, and the right subtree should have values greater than the root.
 * 3. We recursively check the left and right children with updated valid ranges.
 * 4. The valid range for each node depends on the parent node's value.
 * 5. If a node's value is not within the valid range, return false.
 *
 * Time Complexity:
 * - O(N), where N is the number of nodes in the tree.
 * - Each node is visited once, so the time complexity is linear.
 *
 * Space Complexity:
 * - O(H), where H is the height of the tree.
 * - This space is used by the recursion stack. In the worst case (skewed tree), H = O(N). In a balanced tree, H = O(log N).
 */