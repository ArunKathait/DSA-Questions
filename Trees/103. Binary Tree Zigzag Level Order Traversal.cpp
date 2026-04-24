
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;              // value of node
 *     TreeNode *left;       // pointer to left child
 *     TreeNode *right;      // pointer to right child
 * };
 */

class Solution {// TC ---> O(N)                                  SC ---> O(N)
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;   // final result storing level order in zigzag form

        // Edge case: if tree is empty, return empty result
        if(root == NULL) 
        {
            return ans;
        }

        queue<TreeNode*> q;   // queue for BFS (level order traversal)
        q.push(root);        // start with root node

        bool flag = false;  // flag to decide direction
                            // false -> left to right
                            // true  -> right to left

        // BFS traversal
        while(!q.empty()) {

            int size = q.size();          // number of nodes at current level
            vector<int> currentLevel;     // to store current level values

            // process all nodes of current level
            while(size--) 
            {
                auto node = q.front();   // get front node
                q.pop();                // remove it from queue

                currentLevel.push_back(node->val);  // store its value

                // push left child if exists
                if(node->left) 
                {
                    q.push(node->left);
                }

                // push right child if exists
                if(node->right) 
                {
                    q.push(node->right);
                }
            }

            // if flag is true, reverse current level (zigzag effect)
            if(flag) 
            {
                reverse(currentLevel.begin(), currentLevel.end());
            }

            // add processed level into answer
            ans.push_back(currentLevel);

            // toggle direction for next level
            flag = !flag;
        }

        return ans;   // return final zigzag level order
    }
};
