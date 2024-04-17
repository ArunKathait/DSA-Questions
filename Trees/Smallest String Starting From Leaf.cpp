********************************************APPROACH 1st(USING DFS)**********************************************************

class Solution {// TC--->O(N)         SC--->O(N)
public:
    
    // Initialize a string variable to store the smallest string found
    string smallestString = "";
    
    // Depth First Search (DFS) function to traverse the binary tree
    // Parameters:
    //   - root: Pointer to the current node being processed
    //   - currentString: String representing the current path from root to the current node
    void dfs(TreeNode *root,string currentString)
    {
        
         // Base case: If the current node is null, return
        if(root == NULL)
        {
            return ;
        }
        
        // Append the character corresponding to the current node's value to the beginning of the currentString
        currentString = char(root->val + 'a') + currentString;
        
        // If the current node is a leaf node (both left and right children are null)
        if(root->left == NULL && root->right == NULL)
        {
            
            // Update the smallestString if it's empty or if the current string is lexicographically smaller
            if(smallestString == "" || smallestString > currentString)
            {
                smallestString = currentString;
                
                // Return immediately after processing a leaf node
                return ;
            }
        }
        
        // Recursively traverse left and right subtrees
        dfs(root->left,currentString);
        dfs(root->right,currentString);
        
    }
    
    // Main function to find the smallest string from leaf to root in the binary tree
    string smallestFromLeaf(TreeNode* root) {
        
        // Initialize an empty string to store the current path
        string currentString = "";
        
        // Call the DFS function to traverse the binary tree and find the smallest string
        dfs(root,currentString);
        
        // Return the smallest string found
        return smallestString;
    }
};

********************************************APPROACH 2nd(USING BFS)**********************************************************

class Solution {// TC--->O(N)           SC--->O(N)
public:
    // Initialize a string variable to store the smallest string found
    string smallestString = "";
    
    string smallestFromLeaf(TreeNode* root) {
        
        // Initialize a queue to perform level order traversal and store pairs of node pointers and their corresponding strings
        queue<pair<TreeNode*,string>>q;
        
        // Push the root node along with its value converted to a string to the queue
        q.push({root,string(1,root->val + 'a')});
        
        // Perform level order traversal using BFS
        while(!q.empty())
        {
            // Extract the node and its corresponding currentString from the front of the queue
            auto [node,currentString] = q.front();
            q.pop();
            
            // Check if the current node is a leaf node
            if(node->left == NULL && node->right == NULL)
            {
                
                // Update the smallestString if it's empty or if the currentString is lexicographically smaller
                if(smallestString == "" || smallestString > currentString)
                {
                    smallestString = currentString;
                }
            }
            
            // If the left child exists, push it to the queue along with the updated currentString
            if(node->left != NULL)
            {
                q.push({node->left,char(node->left->val + 'a') + currentString});
            }
            
            // If the right child exists, push it to the queue along with the updated currentString
            if(node->right != NULL)
            {
                q.push({node->right,char(node->right->val + 'a') + currentString});
            }
        }
        
        // Return the smallest string found
        return smallestString;
    }
};
