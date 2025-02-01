// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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
    void treeTraversal(TreeNode* root, vector<int> &ans)
    {
        if(root==nullptr)
            return;
        treeTraversal(root->left,  ans);
        ans.push_back(root->val);
        treeTraversal(root->right,  ans);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        treeTraversal(root, ans);
        return ans[k-1];
    }
};

/*
 * Approach:
 * 1. Perform an **inorder traversal** (left-root-right) to store the elements in sorted order.
 * 2. Store the elements in a vector.
 * 3. Return the `k-1` index element from the vector since it's 0-based indexing.
 *
 * Time Complexity:
 * - O(N) for the inorder traversal where N is the number of nodes.
 * - O(1) for accessing the kth element from the vector.
 * - Overall: **O(N)**
 *
 * Space Complexity:
 * - O(N) for storing the inorder traversal elements in a vector.
 * - O(H) for the recursive stack (O(N) in the worst case, O(log N) for a balanced tree).
 * - Overall: **O(N)**
 */