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
    TreeNode* buildTree(vector<int> preorder, int preStart, int preEnd, vector<int> inorder, int inStart, int inEnd, map<int, int>& mp)
    {
        if(preStart>preEnd || inStart>inEnd)
            return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRootIndex = mp[root->val];
        int numsLeft = inRootIndex - inStart;
        root->left = buildTree(preorder, preStart+1, preEnd+numsLeft, inorder, inStart, inRootIndex-1, mp);
        root->right = buildTree(preorder, preStart+numsLeft+1, preEnd, inorder, inRootIndex+1, inEnd, mp);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mp;
        for(int i=0; i<inorder.size(); i++)
            mp[inorder[i]]=i;
        TreeNode* root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
        return root;
    }
};

/**
 * Approach:
 * 1. Use a hashmap (mp) to store the index of each value in the inorder traversal for quick lookup.
 * 2. Recursively construct the tree:
 *    - The first element of the preorder traversal is the root.
 *    - Find the root's index in the inorder traversal.
 *    - The left subtree consists of elements before the root in inorder.
 *    - The right subtree consists of elements after the root in inorder.
 * 3. Recursively build the left and right subtrees using the calculated index ranges.
 *
 * Complexity Analysis:
 * - Time Complexity: O(N) 
 *   - Constructing the hashmap takes O(N).
 *   - Each node is processed once, leading to O(N) recursive calls.
 * - Space Complexity: O(N)
 *   - O(N) for the hashmap.
 *   - O(N) in the worst case for recursion stack (skewed tree).
 *   - O(log N) in the best case (balanced tree).
 */