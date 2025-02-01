// https://leetcode.com/problems/count-good-nodes-in-binary-tree/
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
    void getGoodNodesCount(TreeNode* root, int max, int &count)
    {
        if(root==nullptr)
            return;
        if(root->val>=max)
        {
            count++;
            max=root->val;
        }
        getGoodNodesCount(root->left, max, count);
        getGoodNodesCount(root->right, max, count);
    }

public:
    int goodNodes(TreeNode* root) {
        int count = 0;
        int max = INT_MIN;
        getGoodNodesCount(root ,max, count);
        return count;
    }
};

/*
 * Approach:
 * 1. Perform a depth-first search (DFS) on the binary tree.
 * 2. Keep track of the maximum value encountered so far during the traversal.
 * 3. A node is considered "good" if its value is greater than or equal to the maximum value encountered along the path from the root to that node.
 * 4. At each node, check if its value is greater than or equal to the current maximum value, and if so, increment the count.
 * 5. Continue the DFS traversal recursively on both the left and right subtrees.
 *
 * Time Complexity:
 * - O(N), where N is the number of nodes in the binary tree.
 * - We visit each node once during the DFS traversal.
 *
 * Space Complexity:
 * - O(H), where H is the height of the tree.
 * - This space is used by the recursion stack during the DFS traversal.
 * - In the worst case (skewed tree), H = O(N). In a balanced tree, H = O(log N).
 */