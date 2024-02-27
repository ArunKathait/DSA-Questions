// Using DFS

class Solution {
public:
    // Helper function to calculate the depth of the tree rooted at 'root' and update diameter
    int helper(TreeNode* root, int &diameter) {
        
        // Base case: if the root is NULL, return 0
        if (root == NULL) {
            return 0;
        }
        
        // Recursively calculate the depth of the left subtree
        int left = helper(root->left, diameter);
        
        // Recursively calculate the depth of the right subtree
        int right = helper(root->right, diameter);
        
        // Update the diameter if the sum of depths of left and right subtrees is greater
        diameter = max(diameter, left + right);
        
        // Return the maximum depth of the left and right subtrees + 1 (for the current node)
        return max(left, right) + 1;  
    }
    
    // Main function to calculate the diameter of the binary tree
    int diameterOfBinaryTree(TreeNode* root) {
        
        // Initialize the diameter to 0
        int diameter = 0;
        
        // Call the helper function to calculate the depth and update diameter
        helper(root, diameter);
        
        // Return the diameter of the binary tree
        return diameter;
    }
};   


// Using BFS

class Solution {
public:
    // Function to calculate the height of a binary tree
    int getHeight(TreeNode* root)
    {
        // Base case: if the root is null, return 0
        if (!root) 
        {
            return 0;
        }
        
        // Recursively calculate the height of the left and right subtrees
        // Height of the tree = 1 + maximum height of left and right subtrees
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
    
    // Function to calculate the diameter of a binary tree
    int diameterOfBinaryTree(TreeNode* root) 
    {
        // If the root is null, the diameter is 0
        if (!root) 
        {
            return 0;
        }
        
        // Initialize the diameter to 0
        int diameter = 0;
        
        // Create a queue to perform level order traversal
        queue<TreeNode*> q;
        
        // Add the root node to the queue
        q.push(root);
        
        // Perform level order traversal
        while (!q.empty()) 
        {
            // Get the current node from the front of the queue
            TreeNode* current = q.front();
            q.pop();
            
            // Calculate the height of the left and right subtrees
            int leftHeight = getHeight(current->left);
            int rightHeight = getHeight(current->right);
            
            // Update the diameter if the sum of the heights of left and right subtrees is greater
            diameter = max(diameter, leftHeight + rightHeight);
            
            // Add the left and right child nodes to the queue if they exist
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        
        // Return the diameter of the binary tree
        return diameter;
    }
};
