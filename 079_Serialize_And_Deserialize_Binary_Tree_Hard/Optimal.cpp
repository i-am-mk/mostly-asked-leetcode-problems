// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        if(root==NULL)
            return str;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* front = q.front();
            q.pop();
            if(front==NULL)
                str.append("#,");
            else
            {
                str.append(to_string(front->val)+",");
                q.push(front->left);
                q.push(front->right);
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()==0)
            return NULL;
        stringstream s(data);
        string str="";
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* front = q.front();
            q.pop();
            
            getline(s, str, ',');
            if(str=="#")
                front->left = NULL;
            else
            {
                TreeNode* leftNode = new TreeNode(stoi(str));
                front->left = leftNode;
                q.push(leftNode);
            }

            getline(s,str, ',');
            if(str=="#")
                front->right = NULL;
            else
            {
                TreeNode* rightNode = new TreeNode(stoi(str));
                front->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));


/**
 * Approach:
 * 1️. Serialization (BFS/Level Order Traversal):
 *    - Use a queue to traverse the tree level by level.
 *    - Append each node’s value to the result string.
 *    - Use "#" to represent NULL nodes.
 *    - Separate values using a comma.
 * 
 * 2️. Deserialization:
 *    - Read the first value and create the root node.
 *    - Use a queue to attach left and right children.
 *    - Process nodes in the order they appear in the serialized string.
 *    - If a "#" is encountered, assign NULL.
 * 
 * Time Complexity: O(N)
 *    - Both serialization and deserialization visit each node once.
 *    - Using BFS ensures every node is processed in O(1) per operation.
 * Space Complexity: O(N)
 *    - Queue stores nodes in level order, requiring O(N) space in the worst case.
 *    - The serialized string is also O(N) in length.
 */