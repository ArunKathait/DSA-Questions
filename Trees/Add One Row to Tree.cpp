*************************************************APPROACH 1st(USING DFS)*************************************************

class Solution {// TC--->O(N)          SC--->O(N)
public:
    
    // Depth-first search (DFS) function to add nodes at the specified depth
    void dfs(TreeNode *root,int val,int depth,int currentDepth)
    {
        // Base case: If the root is null, return
        if(root == NULL)
        {
            return ;
        }
        
        // If the current depth is one less than the target depth
        if(currentDepth == depth - 1)
        {
            // Store the previous left and right children of the current node
            TreeNode *previousLeftChild = root->left;
            TreeNode *previousRightChild = root->right;
            
            // Create new nodes with the specified value and assign them as left and right children
            TreeNode *newLeftChild = new TreeNode(val);
            TreeNode *newRightChild = new TreeNode(val);
            root->left = newLeftChild;
            root->right = newRightChild;
            
            // Reassign the previous left and right children to the new nodes
            newLeftChild->left = previousLeftChild;
            newRightChild->right = previousRightChild;
        }
        
        // Recursively call the DFS function for the left and right subtrees
        dfs(root->left,val,depth,currentDepth + 1);
        dfs(root->right,val,depth,currentDepth + 1);
    }
    
    // Function to add a row of nodes with the specified value at the given depth
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        // If the target depth is 1, create a new root node with the specified value
        // and set the original root as its left child
        if(depth == 1)
        {
            TreeNode *newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        
        // Initialize the current depth to 1
        int currentDepth = 1;
        
        // Call the DFS function to add nodes at the specified depth
        dfs(root,val,depth,currentDepth);
        
        // Return the modified root of the tree
        return root;
    }
};

****************************************************APPROACH 2nd****************************************************

class Solution {// TC--->O(N)           SC--->O(N)
public:
    // Function to add a row of nodes with the specified value at the given depth
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        // If the target depth is 1, create a new root node with the specified value
        // and set the original root as its left child
        if(depth == 1)
        {
            TreeNode *newroot = new TreeNode(val);
            newroot->left = root;
            return newroot;
        }
        
        // Initialize a queue for level-order traversal
        queue<TreeNode*>q;
        q.push(root);
        
        // Initialize current depth to 0
        int currentDepth = 0;
        
        // Flag to indicate if the row has been added
        bool rowAdded = false;
        
        // Level-order traversal
        while(!q.empty())
        {
            int size = q.size();
            
            // Increment current depth for each level
            currentDepth++;
            
            while(size--)
            {
                auto front = q.front();
                q.pop();
                
                // Store the previous left and right children of the current node
                TreeNode *previousLeftChild = front->left;
                TreeNode *previousRightChild = front->right;
                
                // If the current depth is one less than the target depth
                if(currentDepth == depth - 1)
                {
                  //Create new nodes with the specified value and assign them as left and right children
                    TreeNode *newLeftChild = new TreeNode(val);
                    TreeNode *newRightChild = new TreeNode(val);
                    front->left = newLeftChild;
                    front->right = newRightChild;
                    
                    // Reassign the previous left and right children to the new nodes
                    newLeftChild->left = previousLeftChild;
                    newRightChild->right = previousRightChild;
                    
                    // Mark rowAdded as true
                    rowAdded = true;
                }
                
                // Enqueue the left and right children if they exist
                if(front->left != NULL)
                {
                    q.push(front->left);
                }
                
                if(front->right != NULL)
                {
                    q.push(front->right);
                }
            }
            
            // If the row has been added, break out of the loop
            if(rowAdded)
            {
                break;
            }
        }
        
        // Return the modified root of the tree
        return root;
    }
};
