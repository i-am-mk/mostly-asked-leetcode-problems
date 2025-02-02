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
            deque<int> temp;
            int level = q.size();
            for(int i=0; i<level; i++)
            {        
                TreeNode* front = q.front();
                q.pop();
                if(leftToRight)
                    temp.push_back(front->val);
                else
                    temp.push_front(front->val);

                if(front->left!=nullptr)
                    q.push(front->left);
                if(front->right!=nullptr)
                    q.push(front->right);            
            }
            ans.push_back(vector<int>(temp.begin(), temp.end()));
            leftToRight=!leftToRight;
        }
        return ans;
    }
};

/**
 * Approach:
 * 1. Perform a level-order traversal using a queue.
 * 2. Use a boolean variable `leftToRight` to track the order of insertion.
 * 3. Use a deque to store elements at each level:
 *    - If `leftToRight` is true, push elements at the back.
 *    - If `leftToRight` is false, push elements at the front (to achieve reverse order).
 * 4. Convert the deque to a vector and store it in the final answer.
 * 5. Toggle `leftToRight` for the next level.
 
 * Time Complexity: O(N), where N is the number of nodes in the tree, since each node is processed once.
 * Space Complexity: O(N), since we use a queue to store nodes and a deque to store level-wise elements.
 */