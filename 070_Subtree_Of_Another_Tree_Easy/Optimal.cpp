// https://leetcode.com/problems/subtree-of-another-tree/
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
    void preorder(TreeNode* root, string& text)
    {
        if(root==nullptr)
        {
            text.append("#");
            return;
        }
        text.append("["+to_string(root->val)+"]");
        preorder(root->left, text);
        preorder(root->right, text);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)
            return false;
        string s1 = "";
        string s2 = "";
        preorder(root, s1);
        preorder(subRoot, s2);
        return s1.find(s2)!=string::npos;
    }
};

/*
 * Approach:
 * 1. Serialize both trees into a string using preorder traversal.
 * 2. Use a unique format with brackets `[]` for node values and `#` for nulls to avoid false positives.
 * 3. Check if `subRoot`'s string representation (`s2`) is a substring of `root`'s string (`s1`).
 *
 * Time Complexity:
 * - O(N + M), where N is the number of nodes in `root` and M is the number of nodes in `subRoot`.
 * - String `find()` operation takes O(N), making the worst case O(N + M).
 *
 * Space Complexity:
 * - O(N + M), due to the storage of serialized strings for both trees.
 * - Recursion stack takes O(H), where H is the height of the tree.
 */