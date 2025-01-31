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
    int getHeight(TreeNode* root, int& longestDiameter)
    {
        if(root==nullptr)
            return 0;
        int left = getHeight(root->left, longestDiameter);
        int right = getHeight(root->right, longestDiameter);
        
        longestDiameter=max(longestDiameter, left+right);
        return 1+max(left, right);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int longestDiameter = 0;
        getHeight(root, longestDiameter);
        return longestDiameter;
    }
};

/**
 * Approach:
 * 1. Use a helper function `getHeight` to calculate the height of each subtree.
 * 2. As we calculate the height, we also update the `longestDiameter` at each node as `left + right`.
 * 3. The height of a node is defined as `1 + max(left, right)`, which allows us to compute the diameter efficiently.
 * 4. The final result is stored in `longestDiameter` and returned from `diameterOfBinaryTree`.

 * Time Complexity:
 * - O(N), where N is the number of nodes in the tree.
 * - Each node is visited once, making the traversal linear.
 
 * Space Complexity:
 * - O(H), where H is the height of the tree (O(log N) for balanced trees, O(N) for skewed trees).
 * - This is due to the recursion stack depth in the worst case.
 */