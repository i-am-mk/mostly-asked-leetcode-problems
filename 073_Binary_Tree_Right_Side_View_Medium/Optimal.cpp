// https://leetcode.com/problems/binary-tree-right-side-view/
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
    void getRightView(TreeNode* root, vector<int> &ans, int level)
    {
        if(root==nullptr)
            return;
        if(level==ans.size())
            ans.push_back(root->val);
        getRightView(root->right, ans, level+1);
        getRightView(root->left, ans, level+1);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        getRightView(root, ans, 0);
        return ans;
    }
};

/*
 * Approach:
 * 1. Perform a depth-first search (DFS) traversal to visit each node.
 * 2. At each level, add the rightmost node (first node encountered when traversing right subtree first).
 * 3. Traverse the right subtree first before the left subtree to ensure the rightmost node at each level is processed.
 * 4. If we reach a level that's not yet in the answer, add the current node's value to the result.
 * 5. The result will give the view of the binary tree from the right side.
 *
 * Time Complexity:
 * - O(N), where N is the number of nodes in the binary tree.
 * - We visit each node once during the DFS traversal.
 *
 * Space Complexity:
 * - O(H), where H is the height of the tree.
 * - This space is used by the recursion stack during DFS.
 * - In the worst case (skewed tree), H = O(N). In a balanced tree, H = O(log N).
 */