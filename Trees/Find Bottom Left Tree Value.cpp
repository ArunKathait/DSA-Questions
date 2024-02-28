//*************************************** Using DFS****************************************************************

class Solution {//TC--->O(N)       SC--->O(N)
public:

    // Define a Depth First Search (DFS) function to traverse the tree
    void dfs(TreeNode* node,int currDepth,int &val,int &maxDepth)
    {
        // If the current node is NULL, return
        if(node == NULL)
        {
            return ;
        }
        
        // If the current depth is greater than the maximum depth seen so far,
        // update the maximum depth and set the value to the current node's value
        if(currDepth > maxDepth)
        {
            maxDepth = currDepth;
            val = node->val;
        }
        
        // Recursively call DFS on the left and right children of the current node,
        // increasing the currDepth by 1 for each recursive call
        dfs(node->left,currDepth + 1,val,maxDepth);
        dfs(node->right,currDepth + 1,val,maxDepth);
    }
    
    // Main function to find the bottom left value in the binary tree
    int findBottomLeftValue(TreeNode* root) {
        
        // Initialize variables to store the maximum depth and the value of the bottom left node
        int maxDepth = -1;
        int val;
        
        // Call the DFS function to traverse the tree, starting from the root node,
        // passing in the initial depth of 0, and updating the maxDepth and val variables
        dfs(root,0,val,maxDepth);
        
        // Return the value of the bottom left node
        return val;
    
    }
};

//*******************************************Using BFS******************************************************************

class Solution {//TC--->O(N)             SC--->O(N)
public:
    // Function to find the bottom left value in a binary tree
    int findBottomLeftValue(TreeNode* root) {
        
        // Create a queue to perform level order traversal of the tree
        queue<TreeNode*>q;
        
        // Enqueue the root node initially
        q.push(root);
        
        // Initialize the variable to store the bottomLeft value
        int bottomLeft = 0;
        
        // Continue traversal until the queue becomes empty
        while(!q.empty())
        {
            // Get the number of nodes at the current level
            int size = q.size();
            
            // Traverse all nodes at the current level
            while(size--)
            {
                // Retrieve the front node from the queue
                TreeNode* node = q.front();
                q.pop();
                
                // Update leftMost with the value of the current node
                bottomLeft = node->val;
                
                // Enqueue the right child if it exists
                if(node->right)
                {
                    q.push(node->right);
                }
                
                // Enqueue the left child if it exists
                if(node->left)
                {
                    q.push(node->left);
                }
            }
        }
        
        // Return the bottomLeft value found during traversal
        return bottomLeft;
    }
};
