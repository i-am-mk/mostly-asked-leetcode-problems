// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return NULL;
        int curr = root->val;
        if(curr > p->val && curr > q->val)
            return lowestCommonAncestor(root->left, p, q);
        if(curr < p->val && curr < q->val)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};

/*
 * Approach:
 * 1. Start from the root and traverse the tree.
 * 2. If both `p` and `q` are smaller than `root->val`, move left.
 * 3. If both `p` and `q` are greater than `root->val`, move right.
 * 4. If `p` and `q` lie on different sides (one in the left subtree, one in the right), return `root` as the LCA.
 *
 * Time Complexity:
 * - O(H), where H is the height of the BST.
 * - In the worst case (skewed tree), H = O(N), making the complexity O(N).
 * - In a balanced BST, H = O(log N), making the complexity O(log N).
 *
 * Space Complexity:
 * - O(H) for the recursion stack (O(N) in the worst case, O(log N) for a balanced tree).
 */