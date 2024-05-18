class Solution {// TC--->O(N)               SC--->O(N)
public:
    // Function to remove leaf nodes with a specific target value from a binary tree.
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        // Base case: if the current node is NULL, simply return NULL.
        if(root == NULL)
        {
            return NULL;
        }
        
        // Recursively call the function for the left subtree.
        root->left = removeLeafNodes(root->left,target);
        
        // Recursively call the function for the right subtree.
        root->right = removeLeafNodes(root->right,target);
        
        // After processing the left and right subtrees, check if the current node is a leaf node
        // and if its value is equal to the target value.
        if(root->left == NULL && root->right == NULL && root->val == target)
        {
            // If it is a leaf node with the target value, return NULL to remove this node.
            return NULL;
        }
        
        // If the current node is not a leaf with the target value, return the current node itself.
        return root;
    }
};
