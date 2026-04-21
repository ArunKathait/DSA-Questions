
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;              // value of the node
 *     TreeNode *left;       // pointer to left child
 *     TreeNode *right;      // pointer to right child
 * };
 */

class Solution {// TC ---> O(N)                                 SC ---> O(N)
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // This will store final answer (level by level nodes)
        vector<vector<int>> ans;

        // If tree is empty, return empty result
        if(root == NULL)
        {
            return ans;
        }

        // Queue is used for BFS (level order traversal)
        queue<TreeNode*> q;

        // Push root node to start traversal
        q.push(root);

        // Loop until queue becomes empty
        while(!q.empty())
        {
            // Number of nodes at current level
            int size = q.size();

            // To store values of current level
            vector<int> currentLevel;

            // Process all nodes of this level
            while(size--)
            {
                // Take front node from queue
                auto node = q.front();
                q.pop();

                // Store its value
                currentLevel.push_back(node->val);

                // If left child exists, push into queue
                if(node->left)
                {
                    q.push(node->left);
                }

                // If right child exists, push into queue
                if(node->right)
                {
                    q.push(node->right);
                }
            }

            // After processing one level, add it to answer
            ans.push_back(currentLevel);
        }

        // Return final result
        return ans;
    }
};
