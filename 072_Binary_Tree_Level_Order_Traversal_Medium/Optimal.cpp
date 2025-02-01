// https://leetcode.com/problems/binary-tree-level-order-traversal/
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int level = q.size();
            vector<int> temp;
            for(int i=0; i<level; i++)
            {
                TreeNode* front = q.front();
                q.pop();
                temp.push_back(front->val);

                if(front->left!=nullptr)
                    q.push(front->left);
                if(front->right!=nullptr)
                    q.push(front->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

/*
 * Approach:
 * 1. Start from the root and traverse the tree using Breadth-First Search (BFS).
 * 2. Use a queue to hold nodes level by level.
 * 3. For each level, process all the nodes and enqueue their children for the next level.
 * 4. Continue this process until all nodes are processed.
 * 5. Return the level order traversal as a 2D vector where each inner vector corresponds to one level of the tree.
 *
 * Time Complexity:
 * - O(N), where N is the number of nodes in the binary tree.
 * - Each node is processed once, and enqueue and dequeue operations take constant time.
 * Space Complexity:
 * - O(N) for the space used by the queue to store the nodes at each level.
 * - In the worst case, the queue will hold all the leaf nodes, which could be O(N) for a full binary tree.
 */