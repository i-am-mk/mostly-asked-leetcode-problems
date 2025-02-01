// https://leetcode.com/problems/binary-tree-maximum-path-sum/
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
    int maxPathSum(TreeNode* root, int& maxPath)
    {
        if(root==nullptr)
            return 0;
        int leftSum = max(0, maxPathSum(root->left, maxPath));
        int rightSum = max(0, maxPathSum(root->right, maxPath));
        maxPath = max(maxPath, leftSum+rightSum+root->val);
        return root->val+max(leftSum, rightSum);
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        maxPathSum(root, maxPath);
        return maxPath;
    }
};

/**
 * Approach:
 * The idea is to traverse the tree recursively and calculate the maximum path sum for each node considering both its left and right subtrees.
 * 1. For each node, we compute the sum of the path that goes through that node, which is the sum of:
 * - the current node's value,
 * - the maximum sum from the left subtree (if positive),
 * - the maximum sum from the right subtree (if positive).
 * 2. We then update the global `maxPath` to store the maximum sum encountered so far, which is the maximum of:
 * - the current value of `maxPath`,
 * - the sum of the left and right paths passing through the node.
 * 3. At each node, we return the maximum sum that can be obtained by including the node and either the left or right subtree (whichever is greater). 
 * 4. This ensures that we don't allow negative paths to contribute to the path sum.
 * 
 * Edge case: If the tree only consists of negative values, the function will correctly return the highest value node as the result.
 * Time Complexity - O(N) We visit each node exactly once and perform constant-time operations at each node. Here, N is the number of nodes in the tree.
 * Space Complexity - O(H) The space complexity is determined by the height of the recursion stack, where H is the height of the tree.
 *   - In the worst case (when the tree is skewed), the space complexity is O(N).
 *   - In the best case (when the tree is balanced), the space complexity is O(log N).
 */