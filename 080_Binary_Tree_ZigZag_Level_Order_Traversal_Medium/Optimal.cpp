// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty())
        {
            int level = q.size();
            vector<int> temp(level);
            for(int i=0; i<level; i++)
            {        
                TreeNode* front = q.front();
                q.pop();

                int index = leftToRight ? i : level - i - 1;
                temp[index] = front->val;

                if(front->left!=nullptr)
                    q.push(front->left);
                if(front->right!=nullptr)
                    q.push(front->right);            
            }
            ans.push_back(temp);
            leftToRight=!leftToRight;
        }
        return ans;
    }
};

/**
 * Approach:
 * 1. Perform a level-order traversal using a queue.
 * 2. Maintain a boolean variable `leftToRight` to track the order.
 * 3. Use a vector `temp` of size `level` to store nodes at each level:
 *    - If `leftToRight` is true, store elements at index `i`.
 *    - If `leftToRight` is false, store elements in reverse order at index `level - i - 1`.
 * 4. Add `temp` to the result and toggle `leftToRight` for the next level.
 
 * Time Complexity: O(N), where N is the number of nodes in the tree, since each node is processed once.
 * Space Complexity: O(N), as we store all nodes in the result and also use a queue for BFS traversal.
 */