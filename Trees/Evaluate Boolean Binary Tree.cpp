
class Solution {// TC--->O(N)               SC--->O(N)
public:
    // Function to evaluate a binary tree based on node values
    bool evaluateTree(TreeNode* root) {
        
        // Check if the current node is a leaf node (no children)
        if(root->left == NULL && root->right == NULL)
        {
            // If it's a leaf node, return its value
            return root->val;
        }
        
        // Evaluate the left subtree
        bool leftResult = evaluateTree(root->left);
        
        // Evaluate the right subtree
        bool rightResult = evaluateTree(root->right);
        
        // Depending on the value of the current node, perform an operation on the results from left and right subtrees
        if(root->val == 2)
        {
            // If the current node's value is 2, return the logical OR of left and right subtree results
            return leftResult || rightResult;
        }
        
        if(root->val == 3)
        {
            // If the current node's value is 3, return the logical AND of left and right subtree results
            return leftResult && rightResult;
        }
        
        // Default case: return false if the current node's value is neither 2 nor 3
        return false;
        
    }
};
