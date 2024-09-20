******************************************************APPROACH 1st******************************************************

class Solution {// TC--->O(N)                          SC--->O(N)
public:
    // Helper function to check if the tree is a valid Binary Search Tree (BST)
    // root  -> current node in the tree
    // min   -> minimum value allowed for the current node
    // max   -> maximum value allowed for the current node
    bool isBST(TreeNode *root,long min,long max)
    {
        // Base case: If the current node is null, it is a valid BST
        if(root == NULL)
        {
            return true;
        }
        
        // Check if the current node's value lies between the allowed min and max values
        if(root->val > min && root->val < max)
        {
            // Recursively check the left subtree:
            // The left child's value must be less than the current node's value (so max becomes root->val)
            bool left = isBST(root->left,min,root->val);
            // Recursively check the right subtree:
            // The right child's value must be greater than the current node's value (so min becomes root->val)
            bool right = isBST(root->right,root->val,max);
            
            // The current tree is a valid BST if both left and right subtrees are valid BSTs
            return (left && right);
        }
        
        // If the current node's value is not in the allowed range, it is not a valid BST
        return false;
    }
    
    // Main function that starts the validation from the root of the tree
    bool isValidBST(TreeNode* root) {
        // Initialize the allowed range for the root node: 
        // Use LONG_MIN as the minimum and LONG_MAX as the maximum
        return isBST(root,LONG_MIN,LONG_MAX);
    }
};

***************************************************APPROACH 2nd*********************************************************

class Solution {// TC--->O(N)                        SC--->O(N)
public:
    // Helper function to check if the tree is a valid Binary Search Tree (BST)
    // root    -> current node in the tree
    // minVal  -> minimum value allowed for the current node
    // maxVal  -> maximum value allowed for the current node
    bool isBST(TreeNode *root,long minVal,long maxVal)
    {
        // Base case: If the current node is null, it's a valid BST (an empty tree is a valid BST)
        if(root == NULL)
        {
            return true;
        }
        
         // Check if the current node's value violates the minVal or maxVal constraints:
        // The node's value must be strictly greater than minVal and strictly less than maxVal.
        if(root->val <= minVal || root->val >= maxVal)
        {
            // If it violates, it's not a valid BST
            return false;
        }
        
        // Recursively check the left subtree:
        // The left child's value must be less than the current node's value (so maxVal becomes root->val)
        bool left = isBST(root->left,minVal,root->val);
        
        // Recursively check the right subtree:
        // The right child's value must be greater than the current node's value (so minVal becomes root->val)
        bool right = isBST(root->right,root->val,maxVal);
        
        // The current tree is a valid BST if both left and right subtrees are valid BSTs
        return (left && right);
    }
    
    // Main function that starts the BST validation from the root of the tree
    bool isValidBST(TreeNode* root) {
        
        // Initialize the allowed range for the root node: 
        // Use LONG_MIN as the minimum and LONG_MAX as the maximum to avoid overflow issues
        return isBST(root,LONG_MIN,LONG_MAX);
    }
};
