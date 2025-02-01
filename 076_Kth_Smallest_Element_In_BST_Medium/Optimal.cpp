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
    void treeTraversal(TreeNode* root, int &count, int &ans, int k)
    {
        if(root==nullptr)
            return;
        treeTraversal(root->left, count, ans, k);
        count++;
        if(count==k)
        {
            ans = root->val;
            return;
        }
        treeTraversal(root->right, count, ans, k);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ans = 0;
        treeTraversal(root, count, ans, k);
        return ans;
    }
};

/*
 * Approach:
 * 1. Perform an **inorder traversal** (left-root-right) as it naturally gives elements in sorted order.
 * 2. Maintain a **count** to keep track of visited nodes.
 * 3. When `count == k`, store the current node's value in `ans` and return.
 * 4. Avoid unnecessary traversal once we find the kth element.
 *
 * Time Complexity:
 * - O(H + k), where H is the height of the tree.
 * - In a balanced BST, H = O(log N), so overall complexity is **O(log N + k)**.
 * - In the worst case (skewed tree), H = O(N), making it **O(N)**.
 *
 * Space Complexity:
 * - O(H) for the recursion stack (O(N) in the worst case, O(log N) for a balanced tree).
 * - Overall: **O(H)**
 */