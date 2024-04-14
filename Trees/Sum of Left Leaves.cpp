class Solution {// TC--->O(N)            SC--->O(h)(i.e height of tree)
public:
    // Function to perform preorder traversal and calculate sum of left leaves
    int preorder(TreeNode *root,int &sum)
    {
        // If the current node is NULL, return 0
        if(root == NULL)
        {
            return 0;
        }
        
        // Check if the left child exists and it's a leaf node (no left or right child)
        if(root->left != NULL && root->left->left == NULL && root->left->right == NULL)
        {
            // If so, add the value of the left leaf node to the sum
            sum += root->left->val;
        }
        
        // Recursively traverse the left subtree
        preorder(root->left,sum);
        
        // Recursively traverse the right subtree
        preorder(root->right,sum);
        
        // Return the sum of left leaves
        return sum;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        
        // Initialize the sum to 0
        int sum = 0;
        
        // Call the preorder traversal function to calculate the sum of left leaves
        preorder(root,sum);
        
        // Return the final sum
        return sum;
    }
};
