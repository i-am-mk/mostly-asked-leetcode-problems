// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    TreeNode* buildTree(vector<int>& preorder, int inStart, int inEnd, unordered_map<int, int>& mp, int& preIndex)
    {
        if(inStart > inEnd)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[preIndex++]);
        int inIndex = mp.at(root->val);
        root->left = buildTree(preorder, inStart, inIndex-1, mp, preIndex);
        root->right = buildTree(preorder, inIndex+1, inEnd, mp, preIndex);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for(int i=0; i<inorder.size(); i++)
            mp[inorder[i]]=i;
        int preIndex = 0;
        TreeNode* root = buildTree(preorder, 0, inorder.size() - 1, mp, preIndex);
        return root;
    }
};

/*
Approach:
1. We are given two arrays, `preorder` and `inorder`, which represent the preorder and inorder traversals of a binary tree.
2. The root of the binary tree is the first element in the preorder traversal.
3. We locate the root in the inorder traversal, which divides the tree into two parts: left and right subtrees.
4. We recursively build the left and right subtrees by using the remaining elements of the preorder and inorder arrays.
5. This process continues until the entire tree is reconstructed.

Time Complexity:
- Building the map `unordered_map<int, int> mp` takes O(N) time, where N is the number of nodes (or the size of the arrays).
- For each node, we recursively call the buildTree function, and each lookup in the unordered_map takes constant time (O(1)).
- The total time complexity is O(N) for the entire algorithm, where N is the number of nodes in the tree.

Space Complexity:
- The space complexity is O(N) for storing the tree (in recursion stack and the `unordered_map`).
- The `unordered_map` stores the indices of the inorder traversal elements, which takes O(N) space.

Optimization Suggestion:
- The use of `unordered_map<int, int>` instead of `map<int, int>` is important. `unordered_map` provides average O(1) lookup time for finding the index of a node in the inorder array, 
- whereas `map` would give an O(log N) lookup time due to its internal balancing mechanism. This optimization ensures that the tree is built more efficiently.
*/