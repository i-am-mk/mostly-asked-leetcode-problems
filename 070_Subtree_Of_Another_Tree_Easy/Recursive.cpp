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
private:
    bool isSame(TreeNode* r1, TreeNode* r2)
    {
        if(r1==nullptr || r2==nullptr)
            return r1==r2;
        return r1->val==r2->val && isSame(r1->left, r2->left) && isSame(r1->right, r2->right);        
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)
            return false;
        if(isSame(root, subRoot))
            return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

/*
 * Approach:
 * 1. The `isSame` function checks if two trees are identical by recursively comparing node values and their left and right subtrees.
 * 2. The `isSubtree` function checks if a tree `subRoot` is a subtree of `root` by:
 *    - Checking if the current node in `root` is identical to `subRoot` using `isSame`.
 *    - If they match, it returns `true`.
 *    - If they don't match, it recursively checks the left and right subtrees of `root`.
 * 3. If a match is found, return `true`, otherwise `false`.

 * Time Complexity:
 * - O(N * M), where:
 *   - `N` is the number of nodes in the `root` tree.
 *   - `M` is the number of nodes in the `subRoot` tree.
 * - For each node in the `root`, we compare the entire `subRoot`, so the time complexity is multiplicative.
 * Space Complexity:
 * - O(H), where `H` is the height of the recursion stack.
 * - In the worst case (unbalanced tree), this can be O(N) for skewed trees.
 * - The recursion depth is limited by the height of the trees, making space complexity O(H).
 */